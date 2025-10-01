/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:10:33 by sming-zh          #+#    #+#             */
/*   Updated: 2025/09/30 13:10:55 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **layout, int x, int y)
{
	if (layout[y][x] == 'V' || layout[y][x] == '1')
		return ;
	layout[y][x] = 'V';
	flood_fill(layout, x + 1, y);
	flood_fill(layout, x - 1, y);
	flood_fill(layout, x, y + 1);
	flood_fill(layout, x, y - 1);
}

void	validate_map_path(t_game *game)
{
	char	**layout;
	int		histo[128];

	layout = ft_strarrdup((const char **) game->map.layout);
	flood_fill(layout, game->player.x, game->player.y);
	generate_histogram(histo, layout);
	if (histo['C'] != 0 || histo['E'] != 0)
		error_exit(game, "Map misconfiguration: incomplete path");
	ft_freestrarray(layout);
}
