/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:26:50 by timtan            #+#    #+#             */
/*   Updated: 2026/02/09 10:52:20 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Increases or decreases all position values by 1.
 * Based on starting point given */
static void	update_position(t_cdlist *start, int iterations, int increase)
{
	int	i;

	i = 0;
	if (start == start->next)
		return ;
	while (i < iterations)
	{
		if (increase)
			start->p += 1;
		else
			start->p -= 1;
		start = start->next;
		i++;
	}
	return ;
}

/* Pushes a node from lst to lst2
 * Does this by creating a new node in lst2,
 * Freeing the top node of lst */
void	push(t_cdlist **lst, t_cdlist **lst2)
{
	t_cdlist	*temp;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	if (ft_cdlstadd(lst2, ft_cdlstnew((*lst)->n, 0, (*lst)->i), 1))
		exit_program(1, lst, lst2, NULL);
	if ((*lst)->prev->p == 0)
		*lst = NULL;
	else
	{
		(*lst)->next->prev = (*lst)->prev;
		(*lst)->prev->next = (*lst)->next;
		*lst = (*lst)->next;
		(*lst)->p = 0;
		update_position((*lst)->next, (*lst)->prev->p - 1, 0);
	}
	free(temp);
	update_position((*lst2)->next, (*lst2)->prev->p + 1, 1);
	return ;
}
