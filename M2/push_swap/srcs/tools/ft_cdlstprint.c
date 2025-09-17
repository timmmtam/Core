/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:28:27 by timtan            #+#    #+#             */
/*   Updated: 2025/09/17 20:08:48 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cdlstprint(t_cdlist *lst)
{
	int	i;
	int	last;

	i = 1;
	last = lst->prev->p + 1;
	while (i <= last)
	{
		ft_printf("Node %d, n = %d, p = %d, i = %d\n", i, lst->n, lst->p, lst->i);
		i++;
		lst = lst->next;
	}
	return ;
}
