/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:04:34 by timtan            #+#    #+#             */
/*   Updated: 2025/07/11 19:36:30 by timtan           ###   ########.fr       */
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

ssize_t	uinttohex(char **buffer, unsigned int n, int type)
{
	ssize_t	i;

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

char	*flag_handler(unsigned int n, int flags, int width, char *fstring)
{
	ssize_t	precision;
	ssize_t	str_len;
	ssize_t	buf_len
	char	*str;

	if (flags & FLAG_PCS || flags & FLAG_MNS)
		flags & ~FLAG_ZRO;
	precision = precision(flags, fstring);
	if (precision == 0 && n == 0)
		return (str = "");
	
char	*x_convert(unsigned int n, int flags, int width, char *fstring)
{
	char	*str;
	char	buffer[9];
	ssize_t	str_len;
	ssize_t	buf_len;

	buf_len = uinttohex(&buffer, n, flags);
	str = flag_handler(n, flags, width, fstring);
	if (buf_len < precision)
		str_len = precision;
	if (width > str_len + alt form)
		pad in front with space;
