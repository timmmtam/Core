/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:01:43 by timtan            #+#    #+#             */
/*   Updated: 2025/07/26 19:31:50 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*s_fill(char *str, char *s, ssize_t start, ssize_t str_len)
{
	ssize_t	i;

	i = 0;
	while (str[start] != '\0' && s[i] != '\0' && i < str_len)
		str[start++] = s[i++];
	return (str);
}

static char	*padding(char *str, size_t size)
{
	size_t	i;
	char	c;

	c = ' ';
	i = 0;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*s_default(char *s, char *str, ssize_t str_len)
{
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	str = padding(str, str_len);
	str = s_fill(str, s, 0, str_len);
	return (str);
}

char	*s_convert(char *s, properties fwp)
{
	char	*str;
	ssize_t	str_len;

	if (!s)
		return (NULL);
	str = NULL;
	str_len = ft_strlen(s);
	if ((fwp.flags & FLAG_PCS) && str_len > fwp.precision)
		str_len = fwp.precision;
	if (fwp.width > str_len)
	{
		str = malloc(fwp.width + 1);
		if (!str)
			return (NULL);
		str = padding(str, fwp.width);
		if (fwp.flags & FLAG_MNS)
			str = s_fill(str, s, 0, str_len);
		else
			str = s_fill(str, s, fwp.width - str_len, str_len);
	}
	else
		str = s_default(s, str, str_len);
	return (str);
}
