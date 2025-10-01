/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:02:20 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/07 16:18:48 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	handle_string(int fd, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	return (ft_putstr_fd(str, fd));
}

int	handle_pointer(int fd, va_list args)
{
	void	*ptr;
	char	*str;
	int		written;

	written = 0;
	ptr = va_arg(args, void *);
	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	if (ft_putstr_fd("0x", fd) == -1)
		return (-1);
	written += 2;
	str = ft_convert_base((unsigned long) ptr, HEX_LOWER);
	written += ft_putstr_fd(str, fd);
	free(str);
	if (written == -1)
		return (-1);
	return (written);
}
