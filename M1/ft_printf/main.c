/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:53:57 by timtan            #+#    #+#             */
/*   Updated: 2025/07/29 20:28:45 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	//char	*s;
	int		bytes1;
	int		bytes2;

	//s = NULL;
	bytes1 = 0;
	bytes2 = 0;
	bytes1 += ft_printf("%-5dL\n", -14);
	bytes2 += printf("%-5dL\n", -14);
	printf("myprintf: %d\n", bytes1);
	printf("oriprintf: %d\n", bytes2);
	return (1);
}
