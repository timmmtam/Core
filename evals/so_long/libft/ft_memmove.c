/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:24:25 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/19 10:24:26 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;
	void	*dest2;

	if (dest == src)
		return (dest);
	index = 0;
	dest2 = dest;
	if (dest > src)
	{
		dest += n - 1;
		src += n - 1;
		while (index++ < n)
			*((unsigned char *) dest--) = *((unsigned char *) src--);
	}
	else
	{
		while (index++ < n)
			*((unsigned char *) dest++) = *((unsigned char *) src++);
	}
	return (dest2);
}
