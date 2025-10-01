/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:46:24 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 14:28:39 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (dlst == NULL)
		return ;
	if (del != NULL)
		del(dlst->content);
	free(dlst);
}
