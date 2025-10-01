/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:14:28 by sming-zh          #+#    #+#             */
/*   Updated: 2025/10/01 13:17:27 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

static void	*image_from_file(void *mlx, char *path_to_xpm, int *size)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path_to_xpm, size, size);
	if (img == NULL)
		ft_printf_fd(2, "Unable to load texture: %s\n", path_to_xpm);
	return (img);
}

void	init_textures(t_game *game)
{
	t_textures	*textures;
	int			*size;

	textures = &game->textures;
	size = &textures->img_size;
	textures->chest = image_from_file(game->mlx, "textures/chest.xpm", size);
	textures->exit = image_from_file(game->mlx, "textures/exit.xpm", size);
	textures->player = image_from_file(game->mlx, "textures/player.xpm", size);
	textures->player_in_portal = image_from_file(game->mlx,
			"textures/player_in_portal.xpm", size);
	textures->space = image_from_file(game->mlx, "textures/space.xpm", size);
	textures->wall = image_from_file(game->mlx, "textures/wall.xpm", size);
}
