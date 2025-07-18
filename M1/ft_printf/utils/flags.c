/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:46:05 by timtan            #+#    #+#             */
/*   Updated: 2025/07/17 16:36:59 by timtan           ###   ########.fr       */
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

char	*width_check(int flags, int width, char	*str)
{
	ssize_t	i;
	ssize_t	str_len;
	char	*new_str;

	i = 0;
	new_str = NULL;
	str_len = 0;
	while (str[str_len])
		str_len++;
	if (width > str_len)
	{
		new_str = malloc(width - str_len + 1);
		if (flags & FLAG_ZRO)
			while(i < (width - str_len + 1))
				new_str[i++] = '0';
		else
			while (i < (width - str_len + 1))
				new_str[i++] = ' ';
		new_str[i] = '\0';
	}
	return (new_str);
}

char	*alt_check(int flags)
{
	char	*str;
	ssize_t	i;

	str = NULL;
	i = 0;
	if (flags & FLAG_ALT)
	{
		str = malloc(3);
		if (!str)
			return (NULL);
		str[i++] = '0';
		if (flags & FLAGS_XXX)
			str[i++] = 'X';
else
			str[i++] = 'x';
		str[i] = '\0';
	}
	return (str);
}
