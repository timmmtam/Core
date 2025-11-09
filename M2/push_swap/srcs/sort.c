/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:14:14 by timtan            #+#    #+#             */
/*   Updated: 2025/11/09 22:37:13 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Assigns a target position to each node in stack_b,
 * By comparing its index value against each alement in stack_a
*/
static void	get_target_p(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int	i;
	int	j;
	int	end_b;
	int	end_a;
	int	target_p;

	if (!*stack_b)
		return ;
	i = 0;
	end_b = (*stack_b)->prev->p;
	end_a = (*stack_a)->prev->p;
	while (i <= end_b)
	{
		target_p = 0;
		j = 0;
		while (j <= end_a)
		{
			if ((*stack_b)->i > (*stack_a)->i)
				target_p += 1;
			*stack_a = (*stack_a)->next;
			j++;
		}
		(*stack_b)->target_p = target_p;
		*stack_b = (*stack_b)->next;
		i++;
	}
}

/*
 * Calculates the amount of moves required for each node-
 * to get to its target position in stack_a.
 * Determines whether the stack should be rotated or reverese rotated,
 * By finding the median of stack_a.
 * still can be optimised for if size_a is even number then target_p = size_a / 2 + 1 is top
*/

static void	calculate_moves(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int	size_a;
	int	size_b;
	int	i;

	if (!*stack_b)
		return ;
	size_a = (*stack_a)->prev->p;
	size_b = (*stack_b)->prev->p;
	i = 0;
	while (i <= size_b)
	{
		if ((*stack_b)->target_p <= (size_a / 2))
			(*stack_b)->moves = ((*stack_b)->target_p * 2) + 1 + (i * 2);
		else
			(*stack_b)->moves = (size_a - (*stack_b)->target_p + 1) * 2 + 2 + (i * 2);
		*stack_b = (*stack_b)->next;
		i++;
	}
}

/*
 * Manually sorts a stack with 3 numbers only.
*/
static void	sort_3(t_cdlist **lst)
{
	if ((*lst)->n < (*lst)->next->n && (*lst)->next->n < (*lst)->prev->n)
		return ;
	else if((*lst)->n < (*lst)->next->n && (*lst)->prev->n > (*lst)->n)
	{
		execute_move("rra", lst, NULL);
		execute_move("sa", lst, NULL);
	}
	else if ((*lst)->n > (*lst)->next->n && (*lst)->prev->n > (*lst)->n)
		execute_move("sa", lst, NULL);
	else if ((*lst)->n < (*lst)->next->n && (*lst)->n > (*lst)->prev->n)
		execute_move("rra", lst, NULL);
	else if ((*lst)->n > (*lst)->next->n && (*lst)->next->n < (*lst)->prev->n)
		execute_move("ra", lst, NULL);
	else if ((*lst)->n > (*lst)->next->n && (*lst)->next->n > (*lst)->prev->n)
	{
		execute_move("sa", lst, NULL);
		execute_move("rra", lst, NULL);
	}
}

/*
 * Pushes all numbers to stack_b in quarters (highest to lowest),
 * Until 3 numbers are remaining in stack_a, then sorts it manually.
 * Calculate the target position and no. of moves to return to stack_a,
 * Then execute one with the least amount of moves.
*/
void	sorting_algorithm(t_cdlist **stack_a, t_cdlist **stack_b)
{
	if ((*stack_a)->prev->p > 2)
		push_to_b(stack_a, stack_b);
	sort_3(stack_a);
	if (is_sorted(*stack_a, *stack_b))
			return ;
	//while (*stack_b)
	//{
	ft_printf("After sort3:\n");
	ft_cdlstprint(*stack_a);
	ft_cdlstprint(*stack_b);
	get_target_p(stack_a, stack_b);
	ft_printf("After get_target_p:\n");
	ft_cdlstprint(*stack_a);
	ft_cdlstprint(*stack_b);
	calculate_moves(stack_a, stack_b);
	ft_printf("After calculate_moves:\n");
	ft_cdlstprint(*stack_a);
	ft_cdlstprint(*stack_b);
	execute_cheapest(stack_a, stack_b);
	//}
}
