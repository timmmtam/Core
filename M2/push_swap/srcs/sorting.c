/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:14:14 by timtan            #+#    #+#             */
/*   Updated: 2025/10/03 19:53:09 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_cdlist *stack_a, t_cdlist *stack_b)
{
	int	i;
	int	end;

	if (!stack_a)
		return (0);
	if (stack_b)
		return (0);
	i = 0;
	end = stack_a->prev->p;
	while (i <= end)
	{
		if (stack_a->p != stack_a->i)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}

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

static void	push_to_b(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int q1;
	int	q2;
	int	q3;

	q1 = (*stack_a)->prev->p / 4;
	q2 = q1 * 2;
	q3 = q1 * 3;
	while ((*stack_a)->prev->p > q2)
	{
		if (((*stack_a)->i > q1 && (*stack_a)->i <= q2) ||
				((*stack_a)->i > q2 && (*stack_a)->i <= q3))
		{
			if ((*stack_a)->i > q1 && (*stack_a)->i < q2)
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

void	sorting_algorithm(t_cdlist **stack_a, t_cdlist **stack_b)
{
	if ((*stack_a)->prev->p > 2)
	{
		push_to_b(stack_a, stack_b);
	}
	sort_3(stack_a);
}
