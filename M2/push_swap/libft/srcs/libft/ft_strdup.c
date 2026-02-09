/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:49:04 by timtan            #+#    #+#             */
/*   Updated: 2025/05/30 16:10:50 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*array;

	if (*s == '\0')
	{
		array = malloc(1);
		array[0] = '\0';
		return (array);
	}
	array = malloc(ft_strlen(s) + 1);
	if (!array)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
