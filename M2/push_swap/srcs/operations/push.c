/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:26:50 by timtan            #+#    #+#             */
/*   Updated: 2025/09/23 19:11:26 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**/
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

void	push(t_cdlist **lst, t_cdlist **lst2)
{
	t_cdlist	*temp;

	temp = *lst;
	if (ft_cdlstadd(lst2, ft_cdlstnew((*lst)->n, 0, (*lst)->i), 1))
		exit_program(1, lst, lst2);
	(*lst)->next->prev = (*lst)->prev;
	(*lst)->prev->next = (*lst)->next;
	*lst = (*lst)->next;
	(*lst)->p = 0;
	update_position((*lst)->next, (*lst)->prev->p - 1, 0);
	free(temp);
	update_position((*lst2)->next, (*lst2)->prev->p + 1, 1);
	return ;
}
