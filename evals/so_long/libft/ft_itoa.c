/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:59:23 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/19 16:59:24 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		len_num;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_num = ft_numlen(n);
	str = malloc(len_num + 1);
	if (!str)
		return (NULL);
	str[len_num--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[len_num--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int u)
{
	unsigned int	len_num;
	char			*str;

	len_num = ft_numlen(u);
	str = malloc(len_num + 1);
	if (!str)
		return (NULL);
	str[len_num--] = '\0';
	str[len_num] = '0';
	while (u > 0)
	{
		str[len_num--] = u % 10 + '0';
		u /= 10;
	}
	return (str);
}

char	*ft_ltoa(long n)
{
	int		len_num;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -9223372036854775807L - 1L)
		return (ft_strdup("-9223372036854775808"));
	len_num = ft_numlen(n);
	str = malloc(len_num + 1);
	if (!str)
		return (NULL);
	str[len_num--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[len_num--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
