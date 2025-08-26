/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:04:44 by timtan            #+#    #+#             */
/*   Updated: 2025/08/01 20:34:21 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*u_convert(unsigned int n, t_properties fwp)
{
	char	*str;
	char	*buffer;
	ssize_t	buf_len;

	if (n == 0 && fwp.precision == 0)
		buffer = NULL;
	else
		buffer = ft_uinttoa(n);
	buf_len = ft_strlen(buffer);
	str = ft_strjoin(pcs_check((ssize_t)n, buf_len, fwp), buffer);
	if (fwp.flags & FLAG_MNS)
		str = ft_strjoin(str, width_check(fwp.flags, fwp.width, str));
	else
		str = ft_strjoin(width_check(fwp.flags, fwp.width, str), str);
	return (str);
}
