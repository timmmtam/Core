/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:42:30 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/19 10:42:32 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	index_src;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	len_dst = 0;
	while (*dst && len_dst < size)
	{
		dst++;
		len_dst++;
	}
	if (len_dst >= size)
		return (len_src + size);
	index_src = 0;
	while (src[index_src] && index_src < size - 1 - len_dst)
	{
		*dst = src[index_src];
		dst++;
		index_src++;
	}
	*dst = '\0';
	return (len_src + len_dst);
}
