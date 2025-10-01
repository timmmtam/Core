/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:01:34 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/23 13:01:35 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index_str;

	str = malloc(ft_strlen(s) + 1);
	if (str)
	{
		index_str = 0;
		while (s[index_str])
		{
			str[index_str] = f(index_str, s[index_str]);
			index_str++;
		}
		str[index_str] = '\0';
	}
	return (str);
}
