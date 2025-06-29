/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:31:40 by timtan            #+#    #+#             */
/*   Updated: 2025/06/30 01:16:33 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		write(1, str, 5);
		free (str);
		str = get_next_line(0);
	}
	return (0);
}
