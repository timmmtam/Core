/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:32:59 by timtan            #+#    #+#             */
/*   Updated: 2025/05/29 17:08:56 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;
	unsigned char		unc;

	if (s == NULL)
		return (NULL);
	unc = (unsigned char)c;
	src = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == unc)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}
