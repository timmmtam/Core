/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_min_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:59:00 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/30 15:17:15 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @return whichever is smaller, else itself
 */
ssize_t	ft_math_min(ssize_t a, ssize_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

/**
 * @return whichever is larger, else itself
 */
ssize_t	ft_math_max(ssize_t a, ssize_t b)
{
	if (a >= b)
		return (a);
	return (b);
}
