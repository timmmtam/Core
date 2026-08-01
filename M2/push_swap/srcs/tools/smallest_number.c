/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:58:40 by timtan            #+#    #+#             */
/*   Updated: 2026/01/25 17:58:02 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns the position of the smallest number in the stack */
int	smallest_number(t_cdlist *stack, int stack_size)
{
	int	i;
	int	smallest;
	int	position;

	i = 0;
	smallest = 100000;
	position = 0;
	while (i <= stack_size)
	{
		if (stack->i < smallest)
		{
			smallest = stack->i;
			position = stack->p;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}
