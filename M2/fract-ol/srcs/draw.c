/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:14:29 by timtan            #+#    #+#             */
/*   Updated: 2026/02/12 16:17:57 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
 * Berntein polynomials, provides continuous color in the range [0,1]
 * 255 is the intensity of colors in the RGB field
 * Latter part is the scale of curve for the polynomial (refer to graph)
 */
/*static int	get_color(double i, t_fractol *fractol)
{
	double	t;
	int		r_value;
	int		g_value;
	int		b_value;

	if (i == fractol->max_iteration)
		return (0x000000);
	t = i / fractol->max_iteration;
	r_value = 255 * 9 * (1 - t) * t * t * t;
	g_value = 255 * 15 * (1 - t) * (1 - t) * t * t;
	b_value = 255 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t;
	return ((r_value << 16) | (g_value << 8) | b_value);
}*/

static void	put_pixel_to_img(t_fractol *fractol, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	offset = (y * fractol->line_size) + (x * (fractol->bpp / 8));
	pixel = fractol->pix_ptr + offset;
	*(unsigned int *)pixel = color;
}

/*
 * Frequency = how fast the colors cycle (higher = more stripes)
 * Phase     = where the color wave starts (offsets R, G, and B)
 */
static int	get_color(double i, t_fractol *fractol)
{
	double	freq;
	int		r;
	int		g;
	int		b;

	if (i == fractol->max_iteration)
		return (0x000000);
	freq = 0.1;
	r = sin(freq * i + 4) * 127 + 128;
	g = sin(freq * i + 2) * 127 + 128;
	b = sin(freq * i + 0) * 127 + 128;
	return ((r << 16) | (g << 8) | b);
}


static void	setup(t_fractol *fractol, int x, int y)
{
	if (fractol->fractal == 2)
	{
		fractol->zx = 0.0;
		fractol->zy = 0.0;
		fractol->cx = (x / fractol->zoom) + fractol->offset_x;
		fractol->cy = (y / fractol->zoom) + fractol->offset_y;
	}
	else
	{
		fractol->zx = x / fractol->zoom + fractol->offset_x;
		fractol->zy = y / fractol->zoom + fractol->offset_y;
	}
}

static void	calculate_fractal(t_fractol *fractol, int x, int y)
{
	double	i;
	int		color;
	double	zx_sq;
	double	zy_sq;

	i = 0;
	setup(fractol, x, y);
	while (i < fractol->max_iteration)
	{
		zx_sq = fractol->zx * fractol->zx;
		zy_sq = fractol->zy * fractol->zy;
		if (zx_sq + zy_sq >= 4.0)
			break ;
		fractol->zy = 2.0 * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = zx_sq - zy_sq + fractol->cx;
		i++;
	}
	color = get_color(i, fractol);
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
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img_ptr, 0, 0);
}
