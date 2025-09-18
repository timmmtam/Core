/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:28:27 by timtan            #+#    #+#             */
/*   Updated: 2025/09/18 18:12:43 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cdlstprint(t_cdlist *lst)
{
	int	i;
	int	last;

	if (!lst)
	{
		write(1, "empty\n\n", 7);
		return ;
	}
	i = 1;
	last = lst->prev->p + 1;
	while (i <= last)
	{
		ft_printf("Node %d, n = %d, p = %d, i = %d\n\n", i, lst->n, lst->p, lst->i);
		i++;
		lst = lst->next;
	}
	return ;
}
