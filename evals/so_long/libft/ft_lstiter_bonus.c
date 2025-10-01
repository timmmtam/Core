/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:45:58 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 14:10:14 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;
	t_list	*tmp;

	node = lst;
	while (node)
	{
		tmp = node->next;
		f(node->content);
		node = tmp;
	}
}
