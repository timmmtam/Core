/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharrepeat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:30:55 by sming-zh          #+#    #+#             */
/*   Updated: 2025/06/04 14:30:56 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putcharrepeat(char c, int amount)
{
	int	n;

	n = 0;
	while (n < amount)
	{
		if (write(1, &c, 1) != 1)
			return (-1);
		n++;
	}
	return (n);
}
