/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:14:14 by timtan            #+#    #+#             */
/*   Updated: 2025/11/02 19:21:50 by timtan           ###   ########.fr       */
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
	/*ft_printf("Stack A:\n");
	ft_cdlstprint(*stack_a);
	ft_printf("Stack B:\n");
	ft_cdlstprint(*stack_b);*/
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

static void	get_target_p(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int	i;
	int	j;
	int	end_b;
	int	end_a;
	int	target_p;

	i = 0;
	j = 0;
	end_b = (*stack_b)->prev->p;
	end_a = (*stack_a)->prev->p;
	while (i <= end_b)
	{
		target_p = 0;
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

/*Calculate moves needed and assign them to stack
still can be optimised for if size_a is even number then target_p = size_a / 2 + 1 is top*/
static void	calculate_moves(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int	size_a;
	int	size_b;
	int	i;

	size_a = (*stack_a)->prev->p;
	size_b = (*stack_b)->prev->p;
	i = 0;
	while (i <= size_b)
	{
		if ((*stack_b)->target_p <= (size_a / 2))
			(*stack_b)->moves = ((*stack_b)->target_p * 2) + 1;
		else if ((*stack_b)->target_p == size_a)
			(*stack_b)->moves = 3;
		else
			(*stack_b)->moves = (size_a - (*stack_b)->target_p + 1) * 2 + 2;
		*stack_b = (*stack_b)->next;
		i++;
	}
}

static void execute_best_move(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int	size_a;
	int	rotate;
	int	i;

	size_a = (*stack_a)->prev->p;
	i = 0;
	if ((*stack_b)->target_p <= size_a / 2)
	{
		rotate = (*stack_b)->target_p;
		while (i++ < rotate)
			execute_move("ra", stack_a, stack_b);
		execute_move("pa", stack_a, stack_b);
		while (i++ <= (*stack_b)->moves)
			execute_move("rra", stack_a, stack_b);
	}
	else
	{
		rotate = ((*stack_b)->moves - 2) / 2;
		while (i++ < rotate)
			execute_move("rra", stack_a, stack_b);
		execute_move("pa", stack_a, stack_b);
		while (i++ <= (*stack_b)->moves)
			execute_move("ra", stack_a, stack_b);
	}
}

void	sorting_algorithm(t_cdlist **stack_a, t_cdlist **stack_b)
{
	if ((*stack_a)->prev->p > 2)
		push_to_b(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		get_target_p(stack_a, stack_b);
		calculate_moves(stack_a, stack_b);
		execute_best_move(stack_a, stack_b);
	}
}
