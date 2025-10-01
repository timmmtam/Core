/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:58:00 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/24 16:35:58 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ft_lstadd_at(t_list **lst, t_list *new, int index)
{
	int		at;
	t_list	*node;

	if (index == 0)
		ft_lstadd_front(lst, new);
	else if (index == ft_lstsize(*lst))
		ft_lstadd_back(lst, new);
	else
	{
		at = 0;
		node = *lst;
		while (at < index - 1)
		{
			node = node->next;
			at++;
		}
		new->next = node->next;
		node->next = new;
	}
}
