/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:08:58 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/19 11:09:00 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	*str1;
	int				index;

	str1 = (unsigned char *)str;
	index = 0;
	while (str1[index])
		index++;
	while (index >= 0)
	{
		if (str1[index] == (unsigned char)c)
			return ((char *) &str1[index]);
		index--;
	}
	return ((void *) 0);
}
