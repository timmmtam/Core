/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnode_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:06:30 by sming-zh          #+#    #+#             */
/*   Updated: 2025/09/07 16:17:33 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_list	*ft_lstnode_at(t_list *lst, int index)
{
	int	at;

	at = 0;
	while (at < index)
	{
		lst = lst->next;
		at++;
	}
	return (lst);
}
