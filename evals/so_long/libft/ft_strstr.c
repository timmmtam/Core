/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:59:43 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/31 14:59:45 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	len_little;

	if (!*little)
		return ((char *) big);
	if (!*big && *little)
		return (NULL);
	len_little = ft_strlen(little);
	while (*big)
	{
		if (ft_strncmp(big, little, len_little) == 0)
			return ((char *) big);
		big++;
	}
	return (NULL);
}
