/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:27:14 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/19 11:27:15 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;

	if (n == 0)
		return (NULL);
	s1 = (const unsigned char *) s;
	while (n > 0)
	{
		if (*s1 == (unsigned char) c)
			return ((void *) s1);
		s1++;
		n--;
	}
	return (NULL);
}
