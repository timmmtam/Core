/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:14:15 by sming-zh          #+#    #+#             */
/*   Updated: 2025/10/01 14:35:52 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include "mlx.h"

void	put_data(t_game *game, int x, int y, char data)
{
	game->map.layout[y][x] = data;
	if (game->map.layout[y][x] == 'P' || game->map.layout[y][x] == 'B')
	{
		game->player.x = x;
		game->player.y = y;
	}
	update_display_xy(game, x, y);
}

void	generate_histogram(int *histo, char **layout)
{
	int		i;
	char	*line;

	ft_bzero(histo, 128 * sizeof(int));
	i = 0;
	while (layout[i] != NULL)
	{
		line = layout[i++];
		while (*line)
		{
			histo[(unsigned char) *line]++;
			line++;
		}
	}
}

int	line_count(const char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	cleanup(t_game *game)
{
	destroy_image(game->mlx, game->textures.chest);
	destroy_image(game->mlx, game->textures.exit);
	destroy_image(game->mlx, game->textures.player);
	destroy_image(game->mlx, game->textures.player_in_portal);
	destroy_image(game->mlx, game->textures.space);
	destroy_image(game->mlx, game->textures.wall);
	if (game->map.layout != NULL)
		ft_freestrarray(game->map.layout);
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	error_exit(t_game *game, const char *msg)
{
	ft_printf_fd(2, "Error\n");
	if (msg != NULL)
		ft_printf_fd(2, "%s\n", msg);
	if (game != NULL)
		cleanup(game);
	exit(1);
}
