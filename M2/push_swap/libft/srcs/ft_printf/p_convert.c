/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:35:08 by timtan            #+#    #+#             */
/*   Updated: 2025/09/13 18:15:32 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	phex_converter(unsigned long long n, int flags)
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

static ssize_t	ullongtohex(char *buffer, unsigned long long n, int flags)
{
	ssize_t	i;

	i = 0;
	while (n > 15 && i < 19)
	{
		buffer[i] = phex_converter(n % 16, flags);
		n /= 16;
		i++;
	}
	buffer[i] = phex_converter(n, flags);
	buffer[i + 1] = '\0';
	buffer = pf_revstr(buffer);
	return (i + 1);
}

static char	*nullcase(void *p, char *buffer, t_properties fwp)
{
	if (!buffer)
		buffer = pf_strdup("(nil)");
	if (!p)
	{
		free(buffer);
		buffer = pf_strdup("(nil)");
	}
	if (fwp.flags & FLAG_MNS)
		buffer = pf_strjoin(buffer, width_check(fwp.flags, fwp.width, buffer));
	else
		buffer = pf_strjoin(width_check(fwp.flags, fwp.width, buffer), buffer);
	return (buffer);
}

char	*p_convert(void *p, t_properties fwp)
{
	char				*buffer;
	char				*str;

	str = NULL;
	buffer = malloc(20);
	if (!buffer || !p)
		return (nullcase(p, buffer, fwp));
	ullongtohex(buffer, (unsigned long long)p, fwp.flags);
	if (fwp.flags & FLAG_ZRO)
	{
		str = pf_strjoin(width_check(fwp.flags, fwp.width - 2, buffer), buffer);
		str = pf_strjoin(alt_check(FLAG_ALT, 1), str);
	}
	else
	{
		str = pf_strjoin(alt_check(FLAG_ALT, 1), buffer);
		if (fwp.flags & FLAG_MNS)
			str = pf_strjoin(str, width_check(fwp.flags, fwp.width, str));
		else
			str = pf_strjoin(width_check(fwp.flags, fwp.width, str), str);
	}
	return (str);
}
