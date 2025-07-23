/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:04:34 by timtan            #+#    #+#             */
/*   Updated: 2025/07/23 19:49:55 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	xhex_converter(unsigned int n, int flags)
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

static char	*uinttohex(char *fstring, unsigned int n, int flags)
{
	char	*buffer;
	ssize_t	i;
	ssize_t	precision;

	buffer = malloc(9);
	if (!buffer)
		return (NULL);
	precision = precision(flags, fstring);
	if (flags & FLAG_PCS)
		if (precision = 0 && n == 0)
		{
			buffer[0] = '\0';
			return (buffer)
		}
	i = 0;
	while (n > 15 && i < 9)
	{
		buffer[i] = xhex_converter(n % 16, flags);
		n /= 16;
		i++;
	}
	buffer[i] = xhex_converter(n, flags);
	buffer[i + 1] = '\0';
	return (ft_revstr(buffer));
}

char	*x_convert(unsigned int n, fwp fwp)
{
	char	*buffer;
	char	*str;
	ssize_t	buf_len;
	ssize_t str_len;

	if (fwp->flags & FLAG_PCS || fwp->flags & FLAG_MNS)
		fwp->flags & ~FLAG_ZRO;
	buffer = uinttohex(&buffer, n, fwp->flags);
	buf_len = ft_strlen(buffer);
	str = ft_strjoin(pcs_check(fwp->flags, fwp->fstring, buf_len), buffer);
	if (fwp->flags & FLAG_ZRO)
	{
		str = ft_strjoin(width_check(fwp->flags, fwp->width, str), str);
		str = ft_strjoin(alt_check(fwp->flags), str);
	}
	else
	{
		str = ft_strjoin(alt_check(fwp->flags), str);
		if (fwp->flags & FLAG_MNS)
			str = ft_strjoin(width_check(fwp->flags, fwp->width, str), str);
		else
			str = ft_strjoin(str, width_check(fwp->flags, fwp->width, str));
	}
	return (str);
}
