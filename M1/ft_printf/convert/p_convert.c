/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:35:08 by timtan            #+#    #+#             */
/*   Updated: 2025/07/24 18:40:00 by timtan           ###   ########.fr       */
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
		*buffer[i] = phex_converter(n % 16, flags);
		n /= 16;
		i++;
	}
	*buffer[i] = phex_converter(n, flags);
	*buffer[i + 1] = '\0';
	return (i + 1);
}

char	*p_convert(void *p, properties fwp)
{
	unsigned long long	address;
	char				*buffer;
	char				*str;
	ssize_t				buf_len;

	if (fwp.flags & FLAG_MNS)
		fwp.flags &= ~FLAG_ZRO;
	str = NULL;
	buffer = malloc(20);
	if (!buffer)
		return (NULL);
	address = (unsigned long long)p;
	buf_len = ullongtohex(&buffer, address, fwp.flags);
	if (fwp.flags & FLAG_ZRO)
	{
		str = ft_strjoin(width_check(fwp.flags, fwp.width, buffer), buffer);
		str = ft_strjoin(alt_check(FLAG_ALT), str);
	}
	else
	{
		str = ft_strjoin(alt_check(FLAG_ALT), buffer);
		str = ft_strjoin(width_check(fwp.flags, fwp.width, str), str);
	}
	return (str);
}
