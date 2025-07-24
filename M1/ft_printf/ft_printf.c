/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:32:14 by timtan            #+#    #+#             */
/*   Updated: 2025/07/24 22:01:11 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes;

	va_start(args, format);
	bytes = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			bytes += fstring_parser((char**)&format, args);
		}
		else
		{
			write(1, format, 1);
			bytes++;
		}
		format++;
	}
	va_end(args);
	return (bytes);
}
