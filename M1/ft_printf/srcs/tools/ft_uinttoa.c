/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uinttoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:08:09 by timtan            #+#    #+#             */
/*   Updated: 2025/08/26 19:01:02 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_array(char *str, unsigned int n, int i)
{
	str[i] = '\0';
	i -= 1;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
}

static int	count_digit(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		count += 1;
	}
	return (count);
}

char	*ft_uinttoa(unsigned int n)
{
	char	*str;
	int		num_len;

	num_len = count_digit(n);
	str = malloc(num_len + 1);
	if (!str)
		return (NULL);
	fill_array(str, n, num_len);
	return (str);
}
