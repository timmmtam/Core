/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:40:54 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/25 14:38:53 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*sub;
	size_t	index;

	if (!*str)
		return (NULL);
	len_s = ft_strlen(str);
	if (start >= len_s)
		return (NULL);
	if (start + len >= len_s)
		len = len_s - start;
	sub = malloc(len + 1);
	if (sub)
	{
		index = 0;
		while (str[start] && index < len)
		{
			sub[index] = str[start];
			index++;
			start++;
		}
		sub[index] = '\0';
	}
	return (sub);
}
