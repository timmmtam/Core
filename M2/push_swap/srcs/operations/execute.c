/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:43:01 by timtan            #+#    #+#             */
/*   Updated: 2025/10/10 12:38:05 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_move(char *str, t_cdlist **stack_a, t_cdlist **stack_b)
{
	if (!stack_a && !stack_b)
		return ;
	if (!ft_strncmp(str, "sa", 3))
		swap(stack_a);
	else if (!ft_strncmp(str, "sb", 3))
		swap(stack_b);
	else if (!ft_strncmp(str, "ra", 3))
		rotate(stack_a);
	else if (!ft_strncmp(str, "rb", 3))
		rotate(stack_b);
	else if (!ft_strncmp(str, "rra", 4))
		r_rotate(stack_a);
	else if (!ft_strncmp(str, "rrb", 4))
		r_rotate(stack_b);
	else if (!ft_strncmp(str, "pa", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb", 3))
		push(stack_a, stack_b);
	ft_printf("%s\n", str);
}
