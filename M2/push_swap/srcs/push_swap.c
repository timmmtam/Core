/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:35:07 by timtan            #+#    #+#             */
/*   Updated: 2025/09/17 21:48:13 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exit_program(int error, t_cdlist **lst)
{
	int	n;

	n = 0;
	if (error)
	{
		write(2, "Error\n", 6);
		n = 1;
	}
	ft_cdlstclear(lst);
	return (n);
}

static int	calculate_index(t_cdlist **lst, int n, int end)
{
	int			index;
	int			i;

	index = 0;
	i = 1;
	while (i < end)
	{
		if (n > (*lst)->n)
			index += 1;
		else if (n < (*lst)->n)
			(*lst)->i += 1;
		else
			return (-1);
		*lst = (*lst)->next;
		i++;
	}
	return (index);
}

int	main (int argc, char **argv)
{
	t_cdlist	*stack_a;
	int			i;

	if (argc == 1)
		return (0);
	stack_a = ft_cdlstnew(ft_atoi(argv[1]), 0, 0);
	//add integrity check here
	i = 2;
	while (i < argc)
	{
		if (ft_cdlstadd(&stack_a, ft_cdlstnew(ft_atoi(argv[i]), i - 1,
						calculate_index(&stack_a, ft_atoi(argv[i]), i)), 0))
			return (exit_program(1, &stack_a));
		//add duplicate number check here
		i++;
	}
	ft_cdlstprint(stack_a);
	ft_printf("\n");
	swap(&stack_a);
	ft_cdlstprint(stack_a);
	ft_printf("\n");
	swap(&stack_a);
	ft_cdlstprint(stack_a);
	ft_printf("\n");
	rotate(&stack_a);
	ft_cdlstprint(stack_a);
	ft_printf("\n");
	r_rotate(&stack_a);
	ft_cdlstprint(stack_a);
	ft_cdlstclear(&stack_a);
	return (0);
}
