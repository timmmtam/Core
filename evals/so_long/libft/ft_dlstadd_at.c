/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:58:00 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/24 16:37:06 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ft_dlstadd_at(t_dlist **dlst, t_dlist *new, int index)
{
	int		at;
	t_dlist	*node;

	if (index == 0)
		ft_dlstadd_front(dlst, new);
	else if (index == ft_dlstsize(*dlst))
		ft_dlstadd_back(dlst, new);
	else
	{
		at = 0;
		node = *dlst;
		while (at < index - 1)
		{
			node = node->next;
			at++;
		}
		new->next = node->next;
		new->next->prev = new;
		new->prev = node;
		node->next = new;
	}
}
