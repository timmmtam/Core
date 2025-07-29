/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:59:27 by timtan            #+#    #+#             */
/*   Updated: 2025/07/30 00:39:30 by timtan           ###   ########.fr       */
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
	}
	if (
	str[i] = '\0';
	return (str);
}

char	*d_convert(int n, properties fwp)
{
	char	*str;
	char	*buffer;
	ssize_t	buf_len;
	int		neg;

	if (n == 0 && fwp.precision == 0)
		buffer = NULL;
	else
		buffer = ft_itoa(n);
	buf_len = ft_strlen(buffer);
	str = ft_strjoin(pcs_check((ssize_t)n, buf_len, fwp), buffer);
	str = ft_strjoin(sign_check(n, fwp.flags), str);
	if (fwp.flags & FLAG_MNS)
		str = ft_strjoin(str, width_check(fwp.flags, fwp.width, str));
	else
		str = ft_strjoin(width_check(fwp.flags, fwp.width, str), str);
	return (str);
}
