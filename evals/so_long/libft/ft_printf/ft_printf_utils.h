/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:16:49 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/07 16:17:40 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

# include <stdarg.h>

typedef struct s_format
{
	char	flags[128];
	int		precision;
	char	specifier;
}	t_format;

int			handle_string(int fd, va_list args);
int			handle_pointer(int fd, va_list args);
int			handle_digit(int fd, va_list args, t_format *format);
int			handle_unsigned_digit(int fd, va_list args, t_format *format);
int			handle_hex(int fd, va_list args, t_format *format);

#endif
