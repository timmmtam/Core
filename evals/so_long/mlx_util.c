/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:11:31 by sming-zh          #+#    #+#             */
/*   Updated: 2025/10/01 13:10:21 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	put_image(t_game *game, void *img, int x, int y)
{
	x *= game->textures.img_size;
	y *= game->textures.img_size;
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}

void	destroy_image(void *mlx, void *img)
{
	if (img != NULL)
		mlx_destroy_image(mlx, img);
}

void	update_display_xy(t_game *game, int x, int y)
{
	void	*img;

	if (game->map.layout[y][x] == 'C')
		img = game->textures.chest;
	else if (game->map.layout[y][x] == 'E')
		img = game->textures.exit;
	else if (game->map.layout[y][x] == 'B')
		img = game->textures.player_in_portal;
	else if (game->map.layout[y][x] == 'P')
		img = game->textures.player;
	else if (game->map.layout[y][x] == '1')
		img = game->textures.wall;
	else
		img = game->textures.space;
	put_image(game, img, x, y);
}

void	update_display(t_game *game)
{
	int		y;
	int		x;

	mlx_clear_window(game->mlx, game->window);
	y = 0;
	while (game->map.layout[y] != NULL)
	{
		x = 0;
		while (game->map.layout[y][x] != '\0')
		{
			update_display_xy(game, x, y);
			x++;
		}
		y++;
	}
}
