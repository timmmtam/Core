/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:02:41 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/24 17:15:31 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strendswith(const char *str, const char *suffix)
{
	str += ft_strlen(str) - ft_strlen(suffix);
	while (*str && *suffix && *str == *suffix)
	{
		str++;
		suffix++;
	}
	if (*suffix == '\0')
		return (1);
	return (0);
}
