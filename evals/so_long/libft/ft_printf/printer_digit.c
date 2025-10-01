/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:38:04 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/07 16:18:34 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	print_sign(int fd, long num, t_format *format)
{
	char	sign;

	sign = 0;
	if (format->flags[' '])
		sign = ' ';
	if (num < 0)
	{
		sign = '-';
		num = -num;
	}
	else if (format->flags['+'] && num >= 0)
		sign = '+';
	if (sign)
	{
		if (ft_putchar_fd(sign, fd) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int	handle_digit(int fd, va_list args, t_format *format)
{
	int		num;
	int		written;

	written = 0;
	num = va_arg(args, int);
	if (num == -2147483648)
		return (ft_putnbr_fd(-2147483648, fd));
	written += print_sign(fd, num, format);
	num = ft_abs(num);
	written += (ft_putnbr_fd(num, fd));
	if (written == -1)
		return (-1);
	return (written);
}

int	handle_unsigned_digit(int fd, va_list args, t_format *format)
{
	unsigned int	num;
	int				written;

	written = 0;
	num = va_arg(args, unsigned int);
	written += print_sign(fd, num, format);
	written += (ft_putnbr_fd(num, fd));
	num = ft_abs(num);
	if (written == -1)
		return (-1);
	return (written);
}

int	handle_hex(int fd, va_list args, t_format *format)
{
	char	*base;
	char	*str;
	int		written;

	written = 0;
	if (format->specifier == 'X')
		base = HEX_UPPER;
	else
		base = HEX_LOWER;
	if (format->flags['#'])
	{
		if (ft_putstr_fd("0x", fd) == -1)
			return (-1);
		written += 2;
	}
	str = ft_convert_base(va_arg(args, unsigned int), base);
	written += ft_putstr_fd(str, fd);
	free(str);
	if (written == -1)
		return (-1);
	return (written);
}
