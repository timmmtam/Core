/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:12:09 by sming-zh          #+#    #+#             */
/*   Updated: 2025/09/30 16:46:36 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

typedef struct s_player
{
	int	x;
	int	y;
	int	chests;
	int	moves;
}	t_player;

typedef struct s_map
{
	char	**layout;
	int		width;
	int		height;
	int		chests;
}	t_map;

typedef struct s_textures
{
	int		img_size;
	void	*chest;
	void	*exit;
	void	*player;
	void	*player_in_portal;
	void	*space;
	void	*wall;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	t_textures	textures;
	t_map		map;
	t_player	player;
}	t_game;

void	init_map(t_game *game, const char *path);
void	init_textures(t_game *game);
void	put_data(t_game *game, int x, int y, char data);
void	put_image(t_game *game, void *img, int x, int y);
void	update_display(t_game *game);
void	update_display_xy(t_game *game, int x, int y);
int		key_event(int keycode, void *param);
int		close_event(void *param);
void	generate_histogram(int *histo, char **layout);
void	destroy_image(void *mlx, void *img);
void	validate_map_path(t_game *game);
int		line_count(const char *path);
void	cleanup(t_game *game);
void	error_exit(t_game *game, const char *msg);

#endif
