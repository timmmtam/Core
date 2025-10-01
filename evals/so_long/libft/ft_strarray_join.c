/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:10:42 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/30 14:57:13 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*copy_contents(const char **array, char deli, char *str)
{
	int		len;
	char	*sub;

	len = 0;
	while (*array)
	{
		sub = (char *) *array;
		while (*sub)
			str[len++] = *sub++;
		array++;
		if (*array)
			str[len++] = deli;
		else
			str[len] = '\0';
	}
	return (str);
}

char	*ft_strarray_join(const char **array, char deli)
{
	int		array_i;
	char	*str;
	int		len;

	array_i = 0;
	len = 0;
	while (array[array_i])
	{
		len += ft_strlen(array[array_i]);
		array_i++;
		if (array[array_i])
			len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	array_i = 0;
	return (copy_contents(array, deli, str));
}
