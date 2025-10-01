/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:09:19 by sming-zh          #+#    #+#             */
/*   Updated: 2025/09/30 13:10:13 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static void	validate_map_2(t_game *game)
{
	int		histo[128];
	char	c;
	int		y;
	int		x;

	generate_histogram(histo, game->map.layout);
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			c = game->map.layout[y][x];
			if (c != 'C' && c != 'E' && c != 'P' && c != '0' && c != '1')
				error_exit(game, "Map misconfig: found unsupported chars");
		}
	}
	if (histo['C'] < 1)
		error_exit(game, "Map misconfig: 'C' must be at least 1");
	else if (histo['E'] != 1)
		error_exit(game, "Map misconfig: 'E' must only be 1");
	else if (histo['P'] != 1)
		error_exit(game, "Map misconfig: 'P' must only be 1");
	validate_map_path(game);
}

static void	validate_map(t_game *game)
{
	t_map	*map;
	int		i;

	map = &game->map;
	map->width = ft_strlen(map->layout[0]);
	i = 0;
	while (i < map->height)
	{
		if (i == 0 || i == map->height - 1)
		{
			if ((int) ft_charcount(map->layout[i], '1') != map->width)
				error_exit(game, "Map misconfig: Walls are incomplete");
		}
		else if ((int) ft_strlen(map->layout[i]) != map->width)
			error_exit(game, "Map misconfig: Invalid dimension");
		else if (!ft_strstartswith(map->layout[i], "1"))
			error_exit(game, "Map misconfig: Walls are incomplete");
		else if (!ft_strendswith(map->layout[i], "1"))
			error_exit(game, "Map misconfig: Walls are incomplete");
		i++;
	}
	validate_map_2(game);
}

static char	*sanitize_line(const char *line)
{
	char	*nl_ptr;

	nl_ptr = ft_strrchr(line, '\n');
	if (nl_ptr != NULL && ft_strlen(nl_ptr) == 1)
		return (ft_substr(line, 0, ft_strlen(line) - 1));
	return (ft_strdup(line));
}

static void	populate_map_data(t_game *game, char *line, int i)
{
	t_map	*map;
	char	*p_ptr;

	map = &game->map;
	map->layout[i] = sanitize_line(line);
	p_ptr = ft_strchr(map->layout[i], 'P');
	if (p_ptr != NULL)
	{
		game->player.x = p_ptr - map->layout[i];
		game->player.y = i;
	}
	map->chests += ft_charcount(map->layout[i], 'C');
}

void	init_map(t_game *game, const char *path)
{
	int		fd;
	t_map	*map;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Unable to read map.");
	map = &game->map;
	map->height = line_count(path);
	map->layout = malloc(sizeof(char *) * (map->height + 1));
	if (map->layout == NULL)
		error_exit(game, "Map malloc failed.");
	line = get_next_line(fd);
	i = 0;
	while (i < map->height)
	{
		populate_map_data(game, line, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map.layout[i] = NULL;
	validate_map(game);
}
