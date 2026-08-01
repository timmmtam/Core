/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:02:10 by timtan            #+#    #+#             */
/*   Updated: 2026/02/12 15:22:03 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/Headers/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*pix_ptr;
	int		bpp;
	int		line_size;
	int		endian;
	int		fractal;
	int		render;
	int		max_iteration;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zoom;
}			t_fractol;

void	iter_tolower(unsigned int i, char *c);
void	draw_fractal(t_fractol *fractol);
int		handle_keystrokes(int key, t_fractol *fractol);
int		handle_mouse(int key, int x, int y, t_fractol *fractol);
int		exit_program(t_fractol *fractol);

#endif
