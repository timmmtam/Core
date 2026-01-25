/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:35:07 by timtan            #+#    #+#             */
/*   Updated: 2026/01/25 18:12:11 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_program(int err, t_cdlist **lst, t_cdlist **lst2, char **str)
{
	if (err)
		write(2, "Error\n", 6);
	if (lst && *lst)
		ft_cdlstclear(lst);
	if (lst2 && *lst2)
		ft_cdlstclear(lst2);
	if (str)
		free_split(str);
	exit(err);
}

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
