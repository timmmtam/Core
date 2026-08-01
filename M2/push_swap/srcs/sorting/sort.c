/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:14:14 by timtan            #+#    #+#             */
/*   Updated: 2026/01/25 17:59:39 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_sort(t_cdlist **stack_a)
{
	int	size_a;
	int	smallest;
	int	i;

	size_a = (*stack_a)->prev->p;
	smallest = smallest_number(*stack_a, size_a);
	i = 0;
	if (smallest <= size_a / 2)
	{
		while (i++ < smallest)
			execute_move("ra", stack_a, NULL);
	}
	else
	{
		while (i++ < size_a - smallest + 1)
			execute_move("rra", stack_a, NULL);
	}
}

/*
 * Assigns a target position to each node in stack_b,
 * By comparing its index value against each alement in stack_a
*/
static void	get_target_p(t_cdlist *stack_a, t_cdlist *stack_b)
{
	int	i;
	int	j;
	int	size_b;
	int	size_a;

	i = 0;
	size_b = stack_b->prev->p;
	size_a = stack_a->prev->p;
	while (i <= size_b)
	{
		j = 0;
		stack_b->target_p = 0;
		while (j++ <= size_a)
		{
			if (stack_b->i > stack_a->i && stack_b->i < stack_a->next->i)
				stack_b->target_p = j;
			stack_a = stack_a->next;
		}
		if (stack_b->target_p == 0)
			stack_b->target_p = smallest_number(stack_a, size_a);
		else if (stack_b->target_p == size_a + 1)
			stack_b->target_p = 0;
		stack_b = stack_b->next;
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
	else if ((*lst)->n < (*lst)->next->n && (*lst)->prev->n > (*lst)->n)
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
void	sort(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int	instructions[7];

	if ((*stack_a)->prev->p == 4)
	{
		execute_move("pb", stack_a, stack_b);
		execute_move("pb", stack_a, stack_b);
	}
	else if ((*stack_a)->prev->p > 2)
		push_to_b(stack_a, stack_b);
	sort_3(stack_a);
	if (is_sorted(*stack_a, *stack_b))
		return ;
	while (*stack_b)
	{
		get_target_p(*stack_a, *stack_b);
		get_instructions(*stack_a, *stack_b, instructions);
		exec_instruction(stack_a, stack_b, instructions);
	}
	if (!is_sorted(*stack_a, *stack_b))
		final_sort(stack_a);
}
