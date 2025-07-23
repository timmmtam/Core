/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:04:44 by timtan            #+#    #+#             */
/*   Updated: 2025/07/23 19:42:00 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*u_convert(unsigned int n, fwp)
{
	char	*str;
	char	*buffer;
	ssize_t	buf_len;

	if (fwp->flags & FLAG_PCS || fwp->flags & FLAG_MNS)
		fwp->flags & ~FLAG_ZRO;
	buffer = ft_uinttoa(n);
	buf_len = ft_strlen(buffer);
	str = ft_strjoin(pcs_check(fwp->flags, fwp->precision, buf_len), buffer);
	if (fwp->flags & FLAG_MNS)
		str = ft_strjoin(width_check(fwp->flags, fwp->width, str), str);
	else
		str = ft_strjoin(str, width_check(fwp->flags, fwp->width, str), str);
	return (str);
}
