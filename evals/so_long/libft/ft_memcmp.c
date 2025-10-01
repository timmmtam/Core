/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:37:14 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/19 11:37:15 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1u;
	unsigned char	*s2u;
	size_t			index;

	if (n == 0)
		return (0);
	s1u = (unsigned char *) s1;
	s2u = (unsigned char *) s2;
	index = 0;
	while (index < n)
	{
		if (s1u[index] != s2u[index])
			return (s1u[index] - s2u[index]);
		index++;
	}
	return (0);
}
