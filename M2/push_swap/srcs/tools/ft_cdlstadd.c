/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:46:24 by timtan            #+#    #+#             */
/*   Updated: 2025/09/18 17:28:25 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cdlstadd(t_cdlist **lst, t_cdlist *new, int front)
{
	t_cdlist	*last;

	if (!new || !lst)
		return (1);
	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return (0);
	}
	new->next = *lst;
	new->prev = (*lst)->prev;
	last = (*lst)->prev;
	last->next = new;
	(*lst)->prev = new;
	if (front)
		*lst = new;
	return (0);
}
