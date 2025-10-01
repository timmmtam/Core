/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:55:49 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 12:54:53 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	if (dlst == NULL)
		return (NULL);
	while (dlst->next)
		dlst = dlst->next;
	return (dlst);
}
