/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:14:14 by timtan            #+#    #+#             */
/*   Updated: 2025/09/23 19:49:04 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_move(char *str, t_cdlist **stack_a, t_cdlist **stack_b)
{
	if (!stack_a && !stack_b)
		return ;
	if (!ft_strncmp(str, "sa", 3))
		swap(stack_a);
	else if (!ft_strncmp(str, "sb", 3))
		swap(stack_b);
	else if (!ft_strncmp(str, "ra", 3))
		rotate(stack_a);
	else if (!ft_strncmp(str, "rb", 3))
		rotate(stack_b);
	else if (!ft_strncmp(str, "rra", 4))
		r_rotate(stack_a);
	else if (!ft_strncmp(str, "rrb", 4))
		r_rotate(stack_b);
	else if (!ft_strncmp(str, "pa", 3))
		push(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb", 3))
		push(stack_b, stack_a);
	ft_printf("%s\n", str);
}

static void	sort_3(t_cdlist **lst)
{
	if ((*lst)->n < (*lst)->next->n && (*lst)->n < (*lst)->prev->n)
	{
		execute_move("rra", lst, NULL);
		execute_move("sa", lst, NULL);
	}
	else if ((*lst)->n > (*lst)->next->n && (*lst)->prev->n > (*lst)->n)
		execute_move("sa", lst, NULL);
	else if ((*lst)->n < (*lst)->next->n && (*lst)->n > (*lst)->prev->n)
		execute_move("rra", lst, NULL);
	else if ((*lst)->n > (*lst)->next->n && (*lst)->next->n > (*lst)->prev->n)
	{
		execute_move("sa", lst, NULL);
		execute_move("rra", lst, NULL);
	}
	else if ((*lst)->n > (*lst)->next->n && (*lst)->next->n < (*lst)->prev->n)
		execute_move("ra", lst, NULL);
}

void	sorting_algorithm(t_cdlist **stack_a, t_cdlist **stack_b)
{
	stack_b = NULL;
	sort_3(stack_a);
}
