/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:16:47 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 14:10:12 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_list	*ft_lstdup(t_list *lst, void *(*dup_content)(void *))
{
	t_list	*lst_clone;
	t_list	*node;

	lst_clone = ft_lstnew(NULL);
	if (dup_content != NULL)
		lst_clone->content = dup_content(lst->content);
	if (lst_clone == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		node = ft_lstnew(NULL);
		if (node == NULL)
			return (lst_clone);
		if (dup_content != NULL)
			node->content = dup_content(lst->content);
		ft_lstadd_back(&lst_clone, node);
		lst = lst->next;
	}
	return (lst_clone);
}
