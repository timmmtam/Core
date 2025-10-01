/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:58:57 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/23 13:58:57 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrn_fd(char *str, int len, int fd)
{
	int	written;

	written = (int) write(fd, str, len);
	if (written != len)
		return (-1);
	return (written);
}

int	ft_putstr_fd(char *str, int fd)
{
	return (ft_putstrn_fd(str, ft_strlen(str), fd));
}
