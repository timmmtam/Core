/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:53:39 by sming-zh          #+#    #+#             */
/*   Updated: 2025/10/01 14:35:48 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_game(t_game *game, const char *map_path)
{
	game->mlx = mlx_init();
	init_map(game, map_path);
	game->textures.img_size = 64;
	game->width = game->map.width * game->textures.img_size;
	game->height = game->map.height * game->textures.img_size;
	game->window = mlx_new_window
		(game->mlx, game->width, game->height, "so_long");
	init_textures(game);
	update_display(game);
	mlx_key_hook(game->window, key_event, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || ft_strendswith(argv[1], ".ber") != 1)
	{
		ft_printf("./so_long <*.ber>\n");
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	init_game(&game, argv[1]);
	mlx_hook(game.window, 17, 0, close_event, &game);
	mlx_loop(game.mlx);
	cleanup(&game);
	return (0);
}
