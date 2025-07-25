/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:35:08 by timtan            #+#    #+#             */
/*   Updated: 2025/07/25 21:30:31 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	phex_converter(unsigned long long n, int flags)
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

static ssize_t	ullongtohex(char **buffer, unsigned long long n, int flags)
{
	ssize_t	i;

	i = 0;
	while (n > 15 && i < 9)
	{
		(*buffer)[i] = phex_converter(n % 16, flags);
		n /= 16;
		i++;
	}
	(*buffer)[i] = phex_converter(n, flags);
	(*buffer)[i + 1] = '\0';
	*buffer = ft_revstr(*buffer);
	return (i + 1);
}

char	*p_convert(void *p, properties fwp)
{
	unsigned long long	address;
	char				*buffer;
	char				*str;
	ssize_t				buf_len;

	str = NULL;
	buffer = malloc(20);
	if (!buffer || !p)
		return (ft_strdup("(nil)"));
	address = (unsigned long long)p;
	buf_len = ullongtohex(&buffer, address, fwp.flags);
	if (fwp.flags & FLAG_ZRO)
	{
		str = ft_strjoin(width_check(fwp.flags, fwp.width - 2, buffer), buffer);
		str = ft_strjoin(alt_check(FLAG_ALT), str);
	}
	else
	{
		str = ft_strjoin(alt_check(FLAG_ALT), buffer);
		if (fwp.flags & FLAG_MNS)
			str = ft_strjoin(str, width_check(fwp.flags, fwp.width, str));
		else
			str = ft_strjoin(width_check(fwp.flags, fwp.width, str), str);
	}
	return (str);
}
