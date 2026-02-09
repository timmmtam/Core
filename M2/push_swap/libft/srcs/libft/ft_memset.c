/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:06:12 by timtan            #+#    #+#             */
/*   Updated: 2025/05/25 19:43:15 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	fill;

	p = (unsigned char *)s;
	fill = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p[i] = fill;
		i++;
	}
	return (s);
}
