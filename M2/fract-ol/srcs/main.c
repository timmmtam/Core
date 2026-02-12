/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:05:10 by timtan            #+#    #+#             */
/*   Updated: 2026/02/12 15:54:26 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractol(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
		exit_program(fractol);
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT,
			"Fract-ol");
	if (!fractol->win_ptr)
		exit_program(fractol);
	fractol->img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->img_ptr)
		exit_program(fractol);
	fractol->pix_ptr = mlx_get_data_addr(fractol->img_ptr, &fractol->bpp,
			&fractol->line_size, &fractol->endian);
	fractol->zoom = 200;
	fractol->offset_x = -2;
	fractol->offset_y = -2;
	fractol->max_iteration = 100;
	if (fractol->fractal == 0)
	{
		fractol->cx = -0.607;
		fractol->cy = -0.419;
	}
	else if (fractol->fractal == 2)
		fractol->offset_x = -2.3;
}

static int	check_param(int argc, char **argv, t_fractol *fractol)
{
	ft_striteri(argv[1], iter_tolower);
	if (argc == 2 || argc == 4)
	{
		if (!ft_strncmp(argv[1], "julia", 6))
		{
			if (argc == 4)
			{
				fractol->fractal = 1;
				fractol->cx = ft_atof(argv[2]);
				fractol->cy = ft_atof(argv[3]);
			}
		}
		else if (!ft_strncmp(argv[1], "mandelbrot", 11))
		{
			fractol->fractal = 2;
			if (argc == 4)
				return (0);
		}
		else
			return (0);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	fractol = (t_fractol){0};
	if (check_param(argc, argv, &fractol))
	{
		init_fractol(&fractol);
		draw_fractal(&fractol);
		mlx_hook(fractol.win_ptr, 17, 0L, exit_program, &fractol);
		mlx_key_hook(fractol.win_ptr, handle_keystrokes, &fractol);
		mlx_mouse_hook(fractol.win_ptr, handle_mouse, &fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
	{
		write(2, "Usage: ./fractol <fractal> <cx> <cy>\n", 37);
		write(2, "Available fractals: Julia, Mandelbrot\n", 38);
		write(2, "**cx and cy values are only available for Julia set.\n", 53);
	}
	return (0);
}
