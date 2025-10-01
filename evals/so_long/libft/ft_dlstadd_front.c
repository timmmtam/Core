/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:26:03 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 19:34:55 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	new->next = *dlst;
	if (*dlst != NULL)
		(*dlst)->prev = new;
	*dlst = new;
}
