/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:35:43 by timtan            #+#    #+#             */
/*   Updated: 2026/01/25 17:58:53 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Returns the bigger number of the two.
 */
static int	big(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

/*
 * Create instructions for to push the node requiring the least moves.
 */
static void	assign_instructions(t_cdlist *stack, int size_a, int p, int ins[])
{
	int	size_b;

	ft_memset(ins, 0, 7 * sizeof(int));
	size_b = stack->prev->p;
	while (stack->p != p)
		stack = stack->next;
	if (p <= size_b / 2)
	{
		ins[0] += p;
		if (stack->target_p <= size_a / 2)
			ins[2] += stack->target_p;
		else
			ins[3] += size_a - stack->target_p + 1;
	}
	else
	{
		ins[1] += size_b - p + 1;
		if (stack->target_p <= size_a / 2)
			ins[2] += stack->target_p;
		else
			ins[3] += size_a - stack->target_p + 1;
	}
}

/*
 * Iterates through the stack to find the node that has the least moves.
 * Returns the position of that node.
 */
static int	find_cheapest_node(t_cdlist *stack)
{
	int	min;
	int	position;
	int	i;
	int	size_b;

	size_b = stack->prev->p;
	min = 10000;
	position = 0;
	i = 0;
	while (i <= size_b)
	{
		if (stack->moves < min)
		{
			min = stack->moves;
			position = stack->p;
		}
		i++;
		stack = stack->next;
	}
	return (position);
}

/*
 * Iterates through stack_b then calculate and assign moves to each node.
 */
static void	calculate_moves(t_cdlist *stk, int size_a)
{
	int	size_b;
	int	i;

	size_b = stk->prev->p;
	i = 0;
	while (i <= size_b / 2)
	{
		stk->moves = 0;
		if (stk->target_p <= size_a / 2)
			stk->moves = big(stk->p, stk->target_p);
		else
			stk->moves = stk->p + size_a - stk->target_p + 1;
		i++;
		stk = stk->next;
	}
	while (i <= size_b)
	{
		stk->moves = 0;
		if (stk->target_p <= size_a / 2)
			stk->moves = size_b - stk->p + stk->target_p + 1;
		else
			stk->moves = big(size_b - stk->p + 1, size_a - stk->target_p + 1);
		i++;
		stk = stk->next;
	}
}

void	get_instructions(t_cdlist *stack_a, t_cdlist *stack_b, int ins[])
{
	int	cheapest_node;

	calculate_moves(stack_b, stack_a->prev->p);
	cheapest_node = find_cheapest_node(stack_b);
	assign_instructions(stack_b, stack_a->prev->p, cheapest_node, ins);
}
