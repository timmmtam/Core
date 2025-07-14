/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:46:05 by timtan            #+#    #+#             */
/*   Updated: 2025/07/15 00:00:43 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pcs_check(int flags, char *fstring, ssize_t buf_len)
{
	ssize_t	precision;
	ssize_t	i;
	char	*str;

	str = NULL;
	precision = precision(flags, fstring);
	i = 0;
	if (precision > buf_len)
	{
		str = malloc(precision - buf_len + 1);
		if (!str)
			return (NULL);
		while (i < (precision - buf_len + 1))
			str[i++] = '0';
		str[i] = '\0';
	}
	return (str);
}

char	*width_check(int flags, int width, ssize_t str_len)
{
	ssize_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (width > str_len)
	{
		str = malloc(width - str_len + 1);
		if (flags & FLAG_ZRO)
			while(i < (width - str_len + 1))
				str[i++] = '0';
		else
			while (i < (width - str_len + 1))
				str[i++] = ' ';
		str[i] = '\0';
	}
	return (str);
}
