/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:42:13 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/30 12:49:22 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*handle_string_replace(const char *str, const char *from,
		const char *to, char *dest)
{
	char		*dest_origin;
	size_t		len_from;
	const char	*to1;

	dest_origin = dest;
	len_from = ft_strlen(from);
	while (*str)
	{
		to1 = to;
		if (ft_strncmp(str, from, len_from) == 0)
		{
			while (*to1)
				*dest++ = *to1++;
			str += len_from;
		}
		else
			*dest++ = *str++;
	}
	*dest = '\0';
	return (dest_origin);
}

/**
 * @param str the string to apply
 * @param from the substring to be replaced
 * @param to the string to replace `from`
 * @return a new string copy
 */
char	*ft_strreplace(const char *str, const char *from, const char *to)
{
	size_t	count_from;
	size_t	total_size;
	char	*str_new;
	int		replaced_size;

	count_from = ft_strcount(str, from);
	if (count_from == 0)
		return ((char *) str);
	replaced_size = (count_from * 2) + (ft_strlen(to) * count_from);
	total_size = ft_strlen(str) - replaced_size + 1;
	str_new = malloc(total_size);
	if (!str_new)
		return ((char *) str);
	return (handle_string_replace(str, from, to, str_new));
}
