/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:04:34 by timtan            #+#    #+#             */
/*   Updated: 2025/09/13 18:15:04 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	xhex_converter(unsigned int n, int flags)
{
	if (n <= 9)
		return ('0' + n);
	else
	{
		if (flags & FLAG_XXX)
			return ('A' + (n - 10));
		else
			return ('a' + (n - 10));
	}
}

static char	*uinttohex(ssize_t precision, unsigned int n, int flags)
{
	char	*buffer;
	ssize_t	i;

	buffer = malloc(9);
	if (!buffer)
		return (NULL);
	if (flags & FLAG_PCS)
	{
		if (precision == 0 && n == 0)
		{
			buffer[0] = '\0';
			return (buffer);
		}
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
	return (pf_revstr(buffer));
}

char	*x_convert(unsigned int n, t_properties fwp)
{
	char	*buffer;
	char	*str;
	ssize_t	buf_len;

	if (n == 0 && fwp.precision == 0)
		buffer = NULL;
	else
		buffer = uinttohex(fwp.precision, n, fwp.flags);
	buf_len = pf_strlen(buffer);
	str = pf_strjoin(pcs_check((ssize_t)n, buf_len, fwp), buffer);
	if (fwp.flags & FLAG_ZRO)
	{
		str = pf_strjoin(width_check(fwp.flags, fwp.width, str), str);
		str = pf_strjoin(alt_check(fwp.flags, n), str);
	}
	else
	{
		str = pf_strjoin(alt_check(fwp.flags, n), str);
		if (fwp.flags & FLAG_MNS)
			str = pf_strjoin(str, width_check(fwp.flags, fwp.width, str));
		else
			str = pf_strjoin(width_check(fwp.flags, fwp.width, str), str);
	}
	return (str);
}
