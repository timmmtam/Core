/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:17:09 by timtan            #+#    #+#             */
/*   Updated: 2026/02/12 16:03:31 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keystrokes(int key, t_fractol *fractol)
{
	if (key == ESC)
		exit_program(fractol);
	if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
	{
		if (key == LEFT)
			fractol->offset_x -= 10 / fractol->zoom;
		else if (key == RIGHT)
			fractol->offset_x += 10 / fractol->zoom;
		else if (key == UP)
			fractol->offset_y -= 10 / fractol->zoom;
		else
			fractol->offset_y += 10 / fractol->zoom;
		draw_fractal(fractol);
	}
	return (0);
}

int	handle_mouse(int key, int x, int y, t_fractol *fractol)
{
	double	mouse_real;
	double	mouse_img;

	mouse_real = (double)x / fractol->zoom + fractol->offset_x;
	mouse_img = (double)y / fractol->zoom + fractol->offset_y;
	if (key == MOUSE_UP || key == MOUSE_DOWN)
	{
		if (key == MOUSE_UP)
		{
			fractol->zoom *= 1.2;
			if (fractol->max_iteration < 500)
				fractol->max_iteration += 2;
		}
		else
		{
			fractol->zoom /= 1.2;
			if (fractol->max_iteration > 100)
				fractol->max_iteration -= 2;
		}
		fractol->offset_x = mouse_real - ((double)x / fractol->zoom);
		fractol->offset_y = mouse_img - ((double)y / fractol->zoom);
		draw_fractal(fractol);
	}
	return (0);
}
