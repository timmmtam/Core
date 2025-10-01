/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:08:50 by sming-zh          #+#    #+#             */
/*   Updated: 2025/10/01 14:41:05 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "X11/keysym.h"

int	close_event(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	cleanup(game);
	exit(0);
	return (1);
}

static void	move_player(t_game *game, int x, int y)
{
	char	player;

	if (game->map.layout[y][x] == '1')
		return ;
	player = 'P';
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	if (game->map.layout[y][x] == 'E')
	{
		if (game->player.chests == game->map.chests)
		{
			cleanup(game);
			exit(0);
		}
		player = 'B';
	}
	if (game->map.layout[y][x] == 'C')
		game->player.chests++;
	if (game->map.layout[game->player.y][game->player.x] == 'B')
		put_data(game, game->player.x, game->player.y, 'E');
	else
		put_data(game, game->player.x, game->player.y, '0');
	put_data(game, x, y, player);
}

int	key_event(int keycode, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *) param;
	if (keycode == XK_Escape)
	{
		cleanup(game);
		exit(0);
	}
	x = 0;
	y = 0;
	if (keycode == XK_w)
		y--;
	else if (keycode == XK_s)
		y++;
	else if (keycode == XK_a)
		x--;
	else if (keycode == XK_d)
		x++;
	if (x != 0 || y != 0)
		move_player(game, game->player.x + x, game->player.y + y);
	return (1);
}
