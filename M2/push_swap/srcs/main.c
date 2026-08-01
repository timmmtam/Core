/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:35:07 by timtan            #+#    #+#             */
/*   Updated: 2026/02/09 10:10:34 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	init_stacks(&stack_a, &stack_b, argc, argv);
	if (is_sorted(stack_a, stack_b))
		exit_program(0, &stack_a, &stack_b, NULL);
	sort(&stack_a, &stack_b);
	exit_program(0, &stack_a, &stack_b, NULL);
}
