/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:59:52 by timtan            #+#    #+#             */
/*   Updated: 2025/07/17 16:28:55 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_convert(char c, int flags, ssize_t width)
{
	char	*str;
	ssize_t	str_len;
	ssize_t	i;

	i = 0;
	strlen = 1;
	if (width > 1)
		strlen = width;
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	if (strlen == width)
	{
		while (i < strlen)
			str[i++] = ' ';
		str[i] = '\0';
	}
	if (flag & FLAG_MNS)
		str[0] = c;
	else
		str[str_len - 1] = c;
	return (str);
}
