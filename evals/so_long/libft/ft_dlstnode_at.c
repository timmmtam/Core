/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnode_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:06:30 by sming-zh          #+#    #+#             */
/*   Updated: 2025/09/07 16:17:29 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_dlist	*ft_dlstnode_at(t_dlist *dlst, int index)
{
	int	at;

	at = 0;
	while (at < index)
	{
		dlst = dlst->next;
		at++;
	}
	return (dlst);
}
