/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:14:53 by sming-zh          #+#    #+#             */
/*   Updated: 2025/09/30 13:14:53 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrdup(const char **arr)
{
	char	**copy;
	int		y;

	copy = (char **) malloc(sizeof(char *) * (ft_strarray_size(arr) + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (arr[y])
	{
		copy[y] = ft_strdup(arr[y]);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}
