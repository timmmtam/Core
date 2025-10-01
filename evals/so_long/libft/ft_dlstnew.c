/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:36:28 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 12:42:37 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdlib.h>

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*dlst;

	dlst = malloc(sizeof(t_dlist));
	if (dlst == NULL)
		return (NULL);
	dlst->prev = NULL;
	dlst->content = content;
	dlst->next = NULL;
	return (dlst);
}
