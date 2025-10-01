/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:55:00 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/19 16:44:35 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	result;
	int	inverted;

	result = 0;
	inverted = 1;
	while (*str && is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			inverted = -inverted;
		str++;
	}
	while (*str && is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * inverted);
}

long	ft_atol(const char *str)
{
	long	result;
	int		inverted;

	result = 0;
	inverted = 1;
	while (*str && is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			inverted = -inverted;
		str++;
	}
	while (*str && is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * inverted);
}
