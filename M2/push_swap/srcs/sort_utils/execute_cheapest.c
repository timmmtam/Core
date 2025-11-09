/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cheapest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:42:53 by timtan            #+#    #+#             */
/*   Updated: 2025/11/09 22:32:18 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Find the node in the stack which requires the least amount of moves.
 * Returns the position of that node.
*/
static int	find_least_moves(t_cdlist *stack)
{
	int	i;
	int	end;
	int	moves;
	int	position;

	i = 0;
	moves = 2147483647;
	end = stack->prev->p;
	position = 0;
	while (i <= end)
	{
		if (stack->moves < moves)
		{
			position = stack->p;
			moves = stack->moves;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

/*
 * Execute the move which has requires the least amount of moves-
 * to get to its target position in stack_a.
*/
void execute_cheapest(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int			size_a;
	int			rotate;
	int			reverse;
	int			i;
	int			node_to_push;

	size_a = (*stack_a)->prev->p;
	i = 0;
	node_to_push = find_least_moves(*stack_b);
	while (i < node_to_push)
	{
		execute_move("rb", stack_a, stack_b);
		i++;
	}
	reverse = i;
	if ((*stack_b)->target_p <= size_a / 2)
	{
		rotate = (*stack_b)->target_p + i;
		while (i++ < rotate)
			execute_move("ra", stack_a, stack_b);
		execute_move("pa", stack_a, stack_b);
		while (i++ < (*stack_b)->moves)
			execute_move("rra", stack_a, stack_b);
	}
	else
	{
		rotate = ((*stack_b)->moves - 2) / 2 + i;
		while (i++ < rotate)
			execute_move("rra", stack_a, stack_b);
		execute_move("pa", stack_a, stack_b);
		while (i++ < (*stack_b)->moves)
			execute_move("ra", stack_a, stack_b);
	}
	i = 0;
	while (i < reverse)
	{
		execute_move("rrb", stack_a, stack_b);
		i++;
	}
}
