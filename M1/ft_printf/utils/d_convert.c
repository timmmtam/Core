/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:59:27 by timtan            #+#    #+#             */
/*   Updated: 2025/07/23 19:39:28 by timtan           ###   ########.fr       */
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

char	*d_convert(int n, fwp fwp)
{
	char	*str;
	char	*buffer;
	ssize_t	buf_len;

	if (fwp->flags & FLAG_PCS || fwp->flags & FLAG_MNS)
		fwp->flags & ~FLAG_ZRO;
	buffer = ft_itoa(n);
	buf_len = ft_strlen(buffer);
	str = ft_strjoin(pcs_check(fwp->flags, fwp->precision, buf_len), buffer);
	str = ft_strjoin(sign_check(n, fwp->flags), str);
	if (fwp->flags & FLAG_MNS)
		str = ft_strjoin(width_check(fwp->flags, fwp->width, str), str);
	else
		str = ft_strjoin(str, width_check(fwp->flags, fwp->width, str), str);
	return (str);
}
