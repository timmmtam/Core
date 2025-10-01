/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:30:00 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/25 14:39:09 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;

	len = ft_strlen(str);
	ptr = (char *) malloc(len + 1);
	if (ptr)
		ft_strlcpy(ptr, str, len + 1);
	return (ptr);
}
