/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:36:15 by timtan            #+#    #+#             */
/*   Updated: 2026/02/12 15:20:00 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	count_decimal(double *result, const char *nptr, int i)
{
	double	power;

	power = 1.0;
	if (nptr[i] == '.')
	{
		i++;
		while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
		{
			*result = *result * 10.0 + (nptr[i] - '0');
			power *= 10.0;
			i++;
		}
	}
	return (power);
}

double	ft_atof(const char *nptr)
{
	int		i;
	double	sign;
	double	result;
	double	power;

	i = 0;
	sign = 1.0;
	result = 0.0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1.0;
		i++;
	}
	if (nptr[i] < '0' && nptr[i] > '9')
		return (0);
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10.0 + (nptr[i] - '0');
		i++;
	}
	power = count_decimal(&result, nptr, i);
	return (result * sign / power);
}
