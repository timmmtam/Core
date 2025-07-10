/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:01:43 by timtan            #+#    #+#             */
/*   Updated: 2025/07/10 23:25:05 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_convert(char *s, int flags, int width, char *fstring)
{
	char	*str;
	size_t	str_len;
	size_t	i;
	size_t	precision;

	i = 0;
	precision = 0;
	str_len = ft_strlen(s);
	if (flags & FLAG_PCS)
		while (*fstring >= '0' && *fstring <= '9')
		{
			precision = precision * 10 + (*fstring - '0');
			fstring++;
		}
	if (str_len > precision)
		str_len = precision;
