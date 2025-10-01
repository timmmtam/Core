/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:35:35 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 13:07:46 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*node;

	if (new == NULL)
		return ;
	if (*dlst == NULL)
	{
		*dlst = new;
		return ;
	}
	node = *dlst;
	while (node->next)
		node = node->next;
	node->next = new;
	new->prev = node;
}
