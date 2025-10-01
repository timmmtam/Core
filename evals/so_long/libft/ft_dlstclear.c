/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:07:35 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 14:08:42 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdlib.h>

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*current;
	t_dlist	*temp;

	current = *dlst;
	while (current)
	{
		temp = current->next;
		ft_dlstdelone(current, del);
		current = temp;
	}
	*dlst = NULL;
}
