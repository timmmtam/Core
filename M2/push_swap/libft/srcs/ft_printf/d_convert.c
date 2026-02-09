/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:59:27 by timtan            #+#    #+#             */
/*   Updated: 2025/09/13 18:15:39 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*sign_check(int n, char *s, t_properties fwp)
{
	char	*str;
	ssize_t	i;

	str = malloc(2);
	if (!str)
		return (NULL);
	i = 0;
	if (n >= 0)
	{
		if (fwp.flags & FLAG_POS)
			str[i++] = '+';
		else if (fwp.flags & FLAG_SPC)
			str[i++] = ' ';
	}
	if (n < 0 && ((!(fwp.flags & FLAG_ZRO)) || fwp.width <= pf_strlen(s)))
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

char	*d_convert(int n, t_properties fwp)
{
	char	*str;
	char	*buffer;
	ssize_t	buf_len;

	if (n == 0 && fwp.precision == 0)
		buffer = NULL;
	else
		buffer = pf_itoa(n);
	if (n < 0)
		fwp.flags |= FLAG_NEG;
	buf_len = pf_strlen(buffer);
	str = pf_strjoin(pcs_check((ssize_t)n, buf_len, fwp), buffer);
	str = pf_strjoin(sign_check(n, str, fwp), str);
	if (fwp.flags & FLAG_MNS)
		str = pf_strjoin(str, width_check(fwp.flags, fwp.width, str));
	else
		str = pf_strjoin(width_check(fwp.flags, fwp.width, str), str);
	return (str);
}
