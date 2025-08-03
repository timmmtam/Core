/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:53:57 by timtan            #+#    #+#             */
/*   Updated: 2025/08/03 17:39:19 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		bytes1;
	int		bytes2;

	bytes1 = 0;
	bytes2 = 0;
	bytes1 += ft_printf("%+.dL\n", 5);
	bytes2 += printf("%+.dL\n", 5);
	printf("myprintf: %d\n", bytes1);
	printf("oriprintf: %d\n", bytes2);
	return (1);
}
