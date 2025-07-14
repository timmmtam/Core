/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:04:34 by timtan            #+#    #+#             */
/*   Updated: 2025/07/15 00:00:41 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_converter(unsigned int n, int flags)
{
	if (n >= 0 && n <= 9)
		return ('0' + n);
	else
	{
		if (flags & FLAG_XXX)
			return ('A' + (n - 10));
		else
			return ('a' + (n - 10));
	}
}

ssize_t	uinttohex(char **buffer, unsigned int n, int flags)
{
	ssize_t	i;
	ssize_t	precision;

	precision = precision(flags, fstring);
	if (flags & FLAG_PCS)
		if (precision = 0 && n == 0)
		{
			*buffer[0] = '\0';
			return (0)
		}
	i = 0;
	while (n > 15 && i < 9)
	{
		*buffer[i] = hex_converter(n % 16, flags);
		n /= 16;
		i++;
	}
	*buffer[i] = hex_converter(n, flags);
	*buffer[i + 1] = '\0';
	return (i + 1);
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

char	*x_convert(unsigned int n, int flags, int width, char *fstring)
{
	char	buffer[9];
	char	*str;
	ssize_t	buf_len;
	ssize_t str_len;

	if (flags & FLAG_PCS || flags & FLAG_MNS)
		flags & ~FLAG_ZRO;
	buf_len = uinttohex(&buffer, n flags);
	str = ft_strjoin(pcs_check(flags, fstring, buf_len), buffer);
	if (flags & FLAG_ZRO)
	{
		str = ft_strjoin(width_check(flags, width, str_len), str);
		str = ft_strjoin(alt_check(flags), str);
	}
	else
	{
		str = ft_strjoin(alt_check(flags), str);
		if (flags & FLAG_MNS)
			str = ft_strjoin(width_check(flags, width, ft_strlen(str)), str);
		else
			str = ft_strjoin(str, width_check(flags, width, ft_strlen(str)));
	}
	return (str);
}
