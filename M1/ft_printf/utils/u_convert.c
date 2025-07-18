/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:04:44 by timtan            #+#    #+#             */
/*   Updated: 2025/07/17 16:34:31 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*u_convert(unsigned int n, int flags, ssize_t width, char *fstring)
{
	char	*str;
	char	*buffer;
	ssize_t	buf_len;

	if (flags & FLAG_PCS || flags & FLAG_MNS)
		flags & ~FLAG_ZRO;
	buffer = ft_uinttoa(n);
	buf_len = ft_strlen(buffer);
	str = ft_strjoin(pcs_check(flags, fstring, buf_len), buffer);
	if (flags & FLAG_MNS)
		str = ft_strjoin(width_check(flags, width, str), str);
	else
		str = ft_strjoin(str, width_check(flags, width, str), str);
	return (str);
}
