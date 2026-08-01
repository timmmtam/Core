/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:01:43 by timtan            #+#    #+#             */
/*   Updated: 2025/08/03 17:08:03 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_convert(char *s, t_properties fwp)
{
	char	*str;
	ssize_t	str_len;

	if (!s)
	{
		if (fwp.flags & FLAG_PCS)
		{
			if (fwp.precision > 5)
				str = ft_strdup("(null)");
			else
				str = NULL;
		}
		else
			str = ft_strdup("(null)");
	}
	else
		str = ft_strdup(s);
	str_len = ft_strlen(str);
	if ((fwp.flags & FLAG_PCS) && str_len > fwp.precision)
		str[fwp.precision] = '\0';
	if (fwp.flags & FLAG_MNS)
		str = ft_strjoin(str, width_check(fwp.flags, fwp.width, str));
	else
		str = ft_strjoin(width_check(fwp.flags, fwp.width, str), str);
	return (str);
}
