/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:46:38 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/07 16:27:33 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdlib.h>

static t_format	*extract_format(const char **str)
{
	t_format	*format;

	if (**str != '%')
		return (NULL);
	(*str)++;
	format = ft_calloc(1, sizeof(t_format));
	if (!format)
		return (NULL);
	while (ft_strchr("# +", **str))
	{
		format->flags[(int) **str] = 1;
		(*str)++;
	}
	if (ft_strchr("cspdiuxX%", **str))
	{
		format->specifier = **str;
		(*str)++;
		return (format);
	}
	free(format);
	return (NULL);
}

static int	print_argument(int fd, va_list args, t_format *format)
{
	if (format->specifier == 'c')
		return (ft_putchar_fd((char) va_arg(args, int), fd));
	if (format->specifier == 's')
		return (handle_string(fd, args));
	if (format->specifier == 'p')
		return (handle_pointer(fd, args));
	if (format->specifier == 'd' || format->specifier == 'i')
		return (handle_digit(fd, args, format));
	if (format->specifier == 'u')
		return (handle_unsigned_digit(fd, args, format));
	if (format->specifier == 'x' || format->specifier == 'X')
		return (handle_hex(fd, args, format));
	if (format->specifier == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

static int	parse_string(int fd, const char *str, va_list args)
{
	t_format	*format;
	int			written;
	int			printed;

	written = 0;
	while (*str)
	{
		format = extract_format(&str);
		if (format)
		{
			printed = print_argument(fd, args, format);
			free(format);
			if (printed == -1)
				return (-1);
			written += printed;
			continue ;
		}
		if (write_result(ft_putchar_fd(*str, 1), &written) == -1)
			return (-1);
		str++;
	}
	return (written);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list		args;
	int			written;

	va_start(args, str);
	written = parse_string(fd, str, args);
	va_end(args);
	return (written);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			written;

	va_start(args, str);
	written = parse_string(1, str, args);
	va_end(args);
	return (written);
}
