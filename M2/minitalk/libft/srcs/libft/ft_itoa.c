/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:03:43 by timtan            #+#    #+#             */
/*   Updated: 2025/06/06 20:32:21 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_array(char *str, int n, int i)
{
	int	nb;

	nb = n;
	str[i] = '\0';
	i -= 1;
	if (n < 0)
		n *= -1;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (nb < 0)
		str[0] = '-';
}

static int	count_digit(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count += 1;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		count += 1;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		num_len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num_len = count_digit(n);
	str = malloc((sizeof(char) * num_len) + 1);
	if (!str)
		return (NULL);
	fill_array(str, n, num_len);
	return (str);
}
