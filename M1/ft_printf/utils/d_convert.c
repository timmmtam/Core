/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:59:27 by timtan            #+#    #+#             */
/*   Updated: 2025/07/17 16:32:36 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*sign_check(int n, int flags)
{
	char	*str;
	ssize_t	i;

	str = malloc(2);
	if (!str)
		return (NULL);
	i = 0;
	if (n >= 0)
	{
		if (flags & FLAG_POS)
			str[i++] = '+';
		else if (flags & FLAG_SPC)
			str[i++] = ' ';
		str[i] = '\0';
		return (str)
	}
	return (NULL);
}

char	*d_convert(int n, int flags, ssize_t width, char *fstring)
{
	char	*str;
	char	*buffer;
	ssize_t	buf_len;

	if (flags & FLAG_PCS || flags & FLAG_MNS)
		flags & ~FLAG_ZRO;
	buffer = ft_itoa(n);
	buf_len = ft_strlen(buffer);
	str = ft_strjoin(pcs_check(flags, fstring, buf_len), buffer);
	str = ft_strjoin(sign_check(n, flags), str);
	if (flags & FLAG_MNS)
		str = ft_strjoin(width_check(flags, width, str), str);
	else
		str = ft_strjoin(str, width_check(flags, width, str), str);
	return (str);
}
