/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:51:17 by timtan            #+#    #+#             */
/*   Updated: 2025/09/16 20:47:49 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cdlstclear(t_cdlist **lst)
{
	t_cdlist	*temp;
	int			i;
	int			end;

	temp = NULL;
	i = 0;
	end = (*lst)->prev->p;
	while (i <= end)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
		i++;
	}
	return ;
}
