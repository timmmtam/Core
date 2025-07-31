/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:53:57 by timtan            #+#    #+#             */
/*   Updated: 2025/07/31 20:25:27 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	//char	*s;
	int		bytes1;
	int		bytes2;

	//s = NULL;
	bytes1 = 0;
	bytes2 = 0;
	bytes1 += ft_printf("%010xL\n", LLONG_MAX);
	bytes2 += printf("%010xL\n", LLONG_MAX);
	printf("myprintf: %d\n", bytes1);
	printf("oriprintf: %d\n", bytes2);
	return (1);
}
