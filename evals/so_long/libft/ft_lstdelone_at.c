/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:15:37 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 14:10:06 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdlib.h>

void	ft_lstdelone_at(t_list **lst, void (*del)(void *), int index)
{
	int		at;
	t_list	*node;
	t_list	*next;

	if (index == 0)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, free);
		*lst = node;
	}
	else
	{
		at = 0;
		node = (*lst);
		while (at < index - 1)
		{
			node = node->next;
			at++;
		}
		next = node->next->next;
		ft_lstdelone(node->next, del);
		node->next = next;
	}
}
