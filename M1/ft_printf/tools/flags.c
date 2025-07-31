/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:46:05 by timtan            #+#    #+#             */
/*   Updated: 2025/07/31 22:06:12 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pcs_check(ssize_t n, ssize_t buf_len, properties fwp)
{
	ssize_t	i;
	char	*str;

	if (n == 0 && (fwp.flags & FLAG_PCS) && (fwp.precision == 0))
		return (ft_strdup(""));
	str = NULL;
	i = 0;
	if (fwp.precision > buf_len)
	{
		str = malloc(fwp.precision - buf_len + 1);
		if (!str)
			return (NULL);
		while (i < (fwp.precision - buf_len))
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
	str_len = ft_strlen(str);
	if (width > str_len)
	{
		new_str = malloc(width - str_len + 1);
		if (flags & FLAG_ZRO)
		{
			if (flags & FLAG_NEG)
				new_str[i++] = '-';
			while(i < (width - str_len))
				new_str[i++] = '0';
		}
		else
		{
			while (i < (width - str_len))
				new_str[i++] = ' ';
		}
		new_str[i] = '\0';
	}
	return (new_str);
}

char	*alt_check(int flags, unsigned int n)
{
	char	*str;
	ssize_t	i;

	str = NULL;
	i = 0;
	if ((flags & FLAG_ALT) && n != 0)
	{
		str = malloc(3);
		if (!str)
			return (NULL);
		str[i++] = '0';
		if (flags & FLAG_XXX)
			str[i++] = 'X';
		else
			str[i++] = 'x';
		str[i] = '\0';
	}
	return (str);
}
