/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:11:47 by timtan            #+#    #+#             */
/*   Updated: 2025/09/17 21:47:48 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_cdlist **lst)
{
	int	i;
	int	end;

	if (!lst)
		return ;
	if (!*lst || (*lst)->next == *lst)
		return ;
	i = 0;
	end = (*lst)->prev->p;
	(*lst)->p = end;
	*lst = (*lst)->next;
	i = 0;
	while (i < end)
	{
		(*lst)->p -= 1;
		*lst = (*lst)->next;
		i++;
	}
	*lst = (*lst)->next;
	return ;
}

void	r_rotate(t_cdlist **lst)
{
	int	i;
	int	end;

	if (!lst)
		return ;
	if (!*lst || (*lst)->next == *lst)
		return ;
	i = 0;
	end = (*lst)->prev->p;
	while (i < end)
	{
		(*lst)->p += 1;
		*lst = (*lst)->next;
		i++;
	}
	(*lst)->p = 0;
	return ;
}
