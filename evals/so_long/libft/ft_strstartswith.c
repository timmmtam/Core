/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:12:55 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/24 17:15:30 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstartswith(const char *str, const char *prefix)
{
	while (*str && *prefix && *str == *prefix)
	{
		str++;
		prefix++;
	}
	if (*prefix == '\0')
		return (1);
	return (0);
}
