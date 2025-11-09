/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:18:18 by timtan            #+#    #+#             */
/*   Updated: 2025/11/09 21:46:52 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_cdlist *stack_a, t_cdlist *stack_b)
{
	int	i;
	int	end;

	if (!stack_a)
		return (0);
	if (stack_b)
		return (0);
	i = 0;
	end = stack_a->prev->p;
	while (i <= end)
	{
		if (stack_a->p != stack_a->i)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}
