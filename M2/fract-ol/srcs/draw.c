/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:14:29 by timtan            #+#    #+#             */
/*   Updated: 2026/02/09 17:57:42 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel_to_img(t_fractol *fractol, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	offset = (y * fractol->line_size) + (x * (fractol->bpp / 8));
	pixel = fractol->pix_ptr + offset;
	*(unsigned int*)pixel = color;
}

/*
 * Frequency = how fast the colors cycle (higher = more stripes)
 * Phase     = where the color wave starts (offsets R, G, and B)
 */
static int	get_sine_color(double i)
{
	double	freq;
	int		r;
	int		g;
	int		b;

	freq = 0.1;
	r = sin(freq * i + 4) * 127 + 128;
	g = sin(freq * i + 2) * 127 + 128;
	b = sin(freq * i + 0) * 127 + 128;

	return ((r << 16) | (g << 8) | b);
}

static void setup(t_fractol *fractol, int x, int y)
{
	if (fractol->fractal == 0 || fractol->fractal == 1)
	{
		fractol->zx = x / fractol->zoom + fractol->offset_x;
		fractol->zy = y / fractol->zoom + fractol->offset_y;
	}
	else
	{
		fractol->zx = 0.0;
		fractol->zy = 0.0;
		fractol->cx = (x / fractol->zoom) + fractol->offset_x;
		fractol->cy = (y / fractol->zoom) + fractol->offset_y;
		fractol->offset_x = -2.3;
	}
}

static void	calculate_fractal(t_fractol *fractol, int x, int y)
{
	double		i;
	int		color;
	double	zx_sq;
	double	zy_sq;

	i = 0;
	setup(fractol, x, y);
	while (++i < MAX_ITERATION)
	{
		zx_sq = fractol->zx * fractol->zx;
		zy_sq = fractol->zy * fractol->zy;
		if (zx_sq + zy_sq >= 4.0)
			break ;
		fractol->zy = 2.0 * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = zx_sq - zy_sq + fractol->cx;
	}
	color = get_sine_color(i);
	if (i == MAX_ITERATION)
		put_pixel_to_img(fractol, x, y, 0x000000);
	else
		put_pixel_to_img(fractol, x, y, color);
}

void	draw_fractal(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			calculate_fractal(fractol, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img_ptr, 0, 0);
}
