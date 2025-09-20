/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:46:24 by timtan            #+#    #+#             */
/*   Updated: 2025/09/20 19:48:47 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cdlstadd(t_cdlist **lst, t_cdlist *new, int front)
{
	t_cdlist	*last;

	if (!new || !lst)
		return (1);
	if (new->i < 0)
		return (1);
	if (new->n < -2147483648 || new->n > 2147483647)
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
