/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:35:07 by timtan            #+#    #+#             */
/*   Updated: 2025/11/09 16:22:51 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_program(int error, t_cdlist **lst, t_cdlist **lst2, char **str)
{
	if (error)
		write(2, "Error\n", 6);
	if (lst && *lst)
		ft_cdlstclear(lst);
	if (lst2 && *lst2)
		ft_cdlstclear(lst2);
	if (str)
		free_split(str);
	exit(error);
}

int	main (int argc, char **argv)
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	init_stacks(&stack_a, &stack_b, argc, argv);
	ft_printf("Stack A:\n");
	ft_cdlstprint(stack_a);
	ft_printf("Stack B:\n");
	ft_cdlstprint(stack_b);
	//execute_move("pb", &stack_a, &stack_b);
	if (is_sorted(stack_a, stack_b))
		exit_program(0, &stack_a, &stack_b, NULL);
	sorting_algorithm(&stack_a, &stack_b);
	ft_printf("Stack A:\n");
	ft_cdlstprint(stack_a);
	ft_printf("Stack B:\n");
	ft_cdlstprint(stack_b);
	exit_program(0, &stack_a, &stack_b, NULL);
}
