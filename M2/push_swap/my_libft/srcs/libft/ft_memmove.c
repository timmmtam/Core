/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:19:19 by timtan            #+#    #+#             */
/*   Updated: 2025/05/29 17:06:36 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	unsigned char		*d;
	const unsigned char	*s;

	temp = malloc(n);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!temp)
		return (NULL);
	ft_memcpy(temp, s, n);
	ft_memcpy(d, temp, n);
	free (temp);
	return (dest);
}*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (n == 0 || d == s || d == NULL || s == NULL)
		return (dest);
	if (d > s && d < s + n)
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
