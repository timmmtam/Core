/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:40:35 by timtan            #+#    #+#             */
/*   Updated: 2025/11/09 21:41:17 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Define each quarter and push starting with q2 and q3.
 * Repeat for q1 and q4.
 * Leaving 3 numbers in stack_a
*/
void	push_to_b(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int q1;
	int	q2;
	int	q3;
	int	checkpoint;

	q1 = (*stack_a)->prev->p / 4;
	q2 = (*stack_a)->prev->p * 2 / 4;
	q3 = (*stack_a)->prev->p * 3 / 4;
	checkpoint = (*stack_a)->prev->p - q2;
	while ((*stack_a)->prev->p != checkpoint)
	{
		if (((*stack_a)->i > q1 && (*stack_a)->i <= q2) ||
				((*stack_a)->i > q2 && (*stack_a)->i <= q3))
		{
			if ((*stack_a)->i > q2 && (*stack_a)->i <= q3)
				execute_move("pb", stack_a, stack_b);
			else
			{
				execute_move("pb", stack_a, stack_b);
				execute_move("rb", stack_a, stack_b);
			}
		}
		else
			execute_move("ra", stack_a, stack_b);
	}
	while ((*stack_a)->prev->p > 2)
	{
		if ((*stack_a)->i >= 0 && (*stack_a)->i <= q1)
		{
			execute_move("pb", stack_a, stack_b);
			execute_move("rb", stack_a, stack_b);
		}
		else
			execute_move("pb", stack_a, stack_b);
	}
}
