/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:21:33 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/23 14:21:34 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_putnbr_fd(long n, int fd)
{
	char	*str;
	int		written;

	written = 0;
	if (n == -9223372036854775807L - 1L)
		return (ft_putstr_fd("-9223372036854775808", fd));
	str = ft_ltoa(n);
	if (!str)
		return (0);
	written = ft_putstr_fd(str, fd);
	free(str);
	return (written);
}
