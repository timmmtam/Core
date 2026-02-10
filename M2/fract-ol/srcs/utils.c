/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:30:37 by timtan            #+#    #+#             */
/*   Updated: 2026/02/09 16:11:36 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_tolower(unsigned int i, char *c)
{
	(void)i;
	if (c)
		*c = ft_tolower((int)*c);
}

int	exit_program(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img_ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	free(fractol->mlx_ptr);
	exit(0);
}
