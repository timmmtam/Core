/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:51:27 by timtan            #+#    #+#             */
/*   Updated: 2025/09/17 20:08:38 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_cdlist **lst)
{
	if (!lst)
		return ;
	if (!*lst || (*lst)->next == *lst)
		return ;
	(*lst)->next->prev = (*lst)->prev;
	(*lst)->prev->next = (*lst)->next;
	(*lst)->prev = (*lst)->next;
	(*lst)->next->next->prev = *lst;
	(*lst)->next = (*lst)->next->next;
	(*lst)->prev->next = *lst;
	*lst = (*lst)->prev;
	(*lst)->p = 0;
	(*lst)->next->p = 1;
	return ;
}
