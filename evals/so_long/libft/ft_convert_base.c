/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:55:47 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/29 12:54:35 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*handle_convert_base(t_ulong n, const char *base, int new_size)
{
	char	*str;
	int		len_base;
	int		i;

	str = (char *) malloc(new_size + 1);
	if (!str)
		return (NULL);
	len_base = (int) ft_strlen(base);
	i = new_size;
	str[i--] = '\0';
	str[i] = '0';
	while (n > 0)
	{
		str[i] = base[n % len_base];
		n /= len_base;
		i--;
	}
	return (str);
}

char	*ft_convert_base(unsigned long n, const char *base)
{
	int				converted_size;
	unsigned long	n2;

	if (ft_strlen(base) < 2)
		return (NULL);
	converted_size = 0;
	n2 = n;
	if (n2 == 0)
		converted_size++;
	while (n2 > 0)
	{
		n2 /= ft_strlen(base);
		converted_size++;
	}
	return (handle_convert_base(n, base, converted_size));
}
