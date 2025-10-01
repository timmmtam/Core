/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strelement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:21:41 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/01 17:29:09 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @param index the index (from 0)
 * @return the index of the string array from the delimeter
 */
char	*ft_strelement(const char *str, char deli, int index)
{
	char	**split;
	char	*word;

	split = ft_split(str, deli);
	if (!split)
		return (NULL);
	if (!split[index])
	{
		ft_freestrarray(split);
		return (NULL);
	}
	word = ft_strdup(split[index]);
	ft_freestrarray(split);
	return (word);
}
