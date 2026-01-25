/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:42:53 by timtan            #+#    #+#             */
/*   Updated: 2026/01/25 18:08:04 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimizer(int i, int j, int k, int ins[])
{
	ins[i] = ins[i] - ins[j];
	ins[k] = ins[j];
	ins[j] = 0;
}

/*
 * Checks whether rr or rrr is possible and change instructions accordingly.
 */
static void	optimize_check(int ins[])
{
	if (ins[0] != 0 && ins[2] != 0)
	{
		if (ins[0] > ins[2])
			optimizer(0, 2, 4, ins);
		else
			optimizer(2, 0, 4, ins);
	}
	if (ins[1] != 0 && ins[3] != 0)
	{
		if (ins[1] > ins[3])
			optimizer(1, 3, 5, ins);
		else
			optimizer(3, 1, 5, ins);
	}
}

/*
 * Performs a final check then executes the given instructions and push.
 */
void	exec_instruction(t_cdlist **stack_a, t_cdlist **stack_b, int ins[])
{
	int		i;
	int		j;
	char	**operations;

	i = 0;
	operations = (char *[]){"rb", "rrb", "ra", "rra", "rr", "rrr"};
	optimize_check(ins);
	while (i < 6)
	{
		j = 0;
		while (j++ < ins[i])
			execute_move(operations[i], stack_a, stack_b);
		i++;
	}
	execute_move("pa", stack_a, stack_b);
}
