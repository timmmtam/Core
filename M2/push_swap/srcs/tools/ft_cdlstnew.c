/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:40:04 by timtan            #+#    #+#             */
/*   Updated: 2025/09/16 19:33:17 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cdlist	*ft_cdlstnew(int n, int position, int index) 
{
	t_cdlist	*new;

	new = malloc(sizeof(t_cdlist));
	if (!new)
		return (NULL);
	new->n = n;
	new->p = position;
	new->i = index;
	new->prev = new;
	new->next = new;
	return (new);
}
