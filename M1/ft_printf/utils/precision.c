/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:40:21 by timtan            #+#    #+#             */
/*   Updated: 2025/07/11 19:15:16 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	precision(int flags, char *fstring)
{
	ssize_t	precision;

	precision = 0;
	if (flags & FLAG_PCS)
	{
		while (*fstring >= '0' && *fstring <= '9')
		{
			precision = precision * 10 + (*fstring - '0');
			fstring++;
		}
		return (precision);
	}
	return (-1);
}
