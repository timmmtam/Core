/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:37:29 by timtan            #+#    #+#             */
/*   Updated: 2025/07/14 23:39:56 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *str1, char *str2,)
{
	ssize_t	str1_len;
	ssize_t	str2_len;
	ssize_t	i;
	char	*str_new;

	if (!str1)
		return (str2);
	if (!str2)
		return (str1);
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	str_new = malloc(str1_len + str2_len + 1);
	if (!str_new)
		return (free (str1), free (str2), NULL);
	i = 0;
	while (i < str1_len)
	{
		str_new[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < str2_len)
		str_new[str1_len++] = buffer[i++];
	str_new[stash_len] = '\0';
	return (free (str1), free (str2), str_new);
}
