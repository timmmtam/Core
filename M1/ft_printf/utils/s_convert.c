/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:01:43 by timtan            #+#    #+#             */
/*   Updated: 2025/07/17 16:39:16 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*s_fill(char *str, char *s, ssize_t start, ssize_t count)
{
	ssize_t	i;

	i = 0;
	while (str[start] != '\0' && s[i] != '\0' && i <= count)
		str[start++] = s[i++];
	return (str);
}

static char	*s_default(char *s, char *str, ssize_t str_len)
{
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	str = s_fill(s, str, 0, str_len);
	return (str);
}

static char	*padding(char *str, size_t size, int pad)
{
	size_t	i;
	char	c;

	i = 0;
	if (pad == 0)
		c = '0';
	else
		c = ' ';
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*s_convert(char *s, int flags, ssize_t width, char *fstring)
{
	char	*str;
	ssize_t	str_len;
	ssize_t	i;
	ssize_t	precision;

	i = 0;
	precision = precision(flags, fstring);
	str_len = ft_strlen(s);
	if (str_len > precision)
		str_len = precision;
	if (width > str_len)
	{
		str = malloc(width + 1);
		if (!str)
			return (NULL);
		str = padding(str, width + 1, 1);
		if (flags & FLAG_MNS)
			str = s_fill(str, s, 0, str_len);
		else
			str = s_fill(str, s, width - str_len, str_len);
	}
	else
		str = s_default(str, str_len);
	return (str);
}
