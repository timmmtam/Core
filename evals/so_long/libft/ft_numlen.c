/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:35:00 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/31 12:35:04 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
/**
 * Counts the length of a number ('-' inclusive)
 */
unsigned int	ft_numlen(long l)
{
	unsigned int	count;

	if (l == 0)
		return (1);
	if (l == -9223372036854775807L - 1L)
		return (20);
	count = 0;
	if (l < 0)
	{
		l = -l;
		count++;
	}
	while (l > 0)
	{
		l /= 10;
		count++;
	}
	return (count);
}
