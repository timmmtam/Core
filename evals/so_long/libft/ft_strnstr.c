/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:44:36 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/19 11:44:38 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index_big;
	size_t	len_little;

	if (!*little)
		return ((char *) big);
	if (!*big && *little)
		return (NULL);
	if (len == 0 && *little)
		return (NULL);
	if (ft_strlen(little) > len)
		return (NULL);
	index_big = 0;
	len_little = ft_strlen(little);
	while (*big && index_big < len)
	{
		if (ft_strncmp(big, little, len_little) == 0)
			if (len - index_big >= len_little)
				return ((char *) big);
		big++;
		index_big++;
	}
	return (NULL);
}
