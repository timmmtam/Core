/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:41:14 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/30 12:41:15 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcount(const char *big, const char *little)
{
	size_t	len_little;
	size_t	count;

	len_little = ft_strlen(little);
	count = 0;
	while (big && *big)
	{
		big = ft_strnstr(big, little, ft_strlen(big));
		if (big)
		{
			big += len_little;
			count++;
		}
	}
	return (count);
}
