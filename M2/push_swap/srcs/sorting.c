/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:14:14 by timtan            #+#    #+#             */
/*   Updated: 2025/09/22 15:41:21 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_cdlist *lst)
{
	if (lst->n < lst->next->n && lst->n < lst->prev->n)
	{
		execute_move("rra", lst, NULL);
		execute_move("sa", lst, NULL);
	}
	if (lst->n > lst->next->n && lst->prev->n > lst->n)
		execute_move("sa", lst, NULL);
	if (lst->n < lst->next->n && lst->n > lst->prev->n)
		execute_move("rra", lst, NULL);
	if (lst->n > lst->next->n && lst->next->n > lst->prev->n)
	{
		execute_move("sa", lst, NULL);
		execute_move("rra", lst, NULL);
	}
	if (lst->n > lst->next->n && lst->next->n < lst->prev->n)
		execute_move("ra", lst, NULL);
}

void	sorting_algorithm(t_cdlist **stack_a, t_cdlist **stack_b)
{
	sort_3(*stack_a, *stack_b);
