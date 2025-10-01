/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:20:21 by sming-zh          #+#    #+#             */
/*   Updated: 2025/09/01 18:07:48 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/**
 * @return whether the string is an integer (42, -42, +42)
 */
int	ft_strisnum(const char *str)
{
	if (is_sign(*str))
		str++;
	if (!*str || !ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
