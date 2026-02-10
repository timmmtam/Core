/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:17:09 by timtan            #+#    #+#             */
/*   Updated: 2026/02/09 18:36:32 by timtan           ###   ########.fr       */
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
			fractol->offset_x -= 0.01;
		else if (key == RIGHT)
			fractol->offset_x += 0.01;
		else if (key == UP)
			fractol->offset_y -= 0.01;
		else
			fractol->offset_y += 0.01;
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
			fractol->zoom *= 1.2;
		else
			fractol->zoom /= 1.2;
		fractol->offset_x = mouse_real - ((double)x / fractol->zoom);
		fractol->offset_y = mouse_img - ((double)y / fractol->zoom);
		draw_fractal(fractol);
	}
	return (0);
}
