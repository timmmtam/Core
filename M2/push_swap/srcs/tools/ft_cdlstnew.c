/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:40:04 by timtan            #+#    #+#             */
/*   Updated: 2026/01/25 17:57:25 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cdlist	*ft_cdlstnew(long n, int position, int index)
{
	t_cdlist	*new;

	if (index < 0)
		return (NULL);
	if (n < -2147483648 || n > 2147483647)
		return (NULL);
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
