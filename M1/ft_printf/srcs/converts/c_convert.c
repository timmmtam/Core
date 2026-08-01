/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:59:52 by timtan            #+#    #+#             */
/*   Updated: 2025/08/26 17:34:50 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_convert(char c, t_properties fwp)
{
	int	bytes;

	bytes = 0;
	if (fwp.flags & FLAG_MNS)
	{
		bytes += (int)write (1, &c, 1);
		bytes += ft_printstr(width_check(fwp.flags, fwp.width, "c"));
	}
	else
	{
		bytes += ft_printstr(width_check(fwp.flags, fwp.width, "c"));
		bytes += (int)write (1, &c, 1);
	}
	return (bytes);
}
