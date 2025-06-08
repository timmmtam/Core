/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:58:58 by timtan            #+#    #+#             */
/*   Updated: 2025/05/29 19:29:54 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (big == NULL || little == NULL)
		return (NULL);
	little_len = ft_strlen(little);
	i = 0;
	if (len < little_len)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (i <= len - little_len)
	{
		if (big[i] == '\0')
			return (NULL);
		if (big[i] == little[0])
			if (ft_strncmp(&big[i], little, little_len) == 0)
				return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
