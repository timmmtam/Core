/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:35:07 by timtan            #+#    #+#             */
/*   Updated: 2025/09/23 19:40:57 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_program(int error, t_cdlist **lst, t_cdlist **lst2)
{
	if (error)
		write(2, "Error\n", 6);
	if (lst && *lst)
		ft_cdlstclear(lst);
	if (lst2 && *lst2)
		ft_cdlstclear(lst2);
	exit(error);
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

int	integrity_check(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] != '\0')
		{
			if (!(av[j][i] >= '0' && av[j][i] <= '9') && !(av[j][i] == '-')
					&& !(av[j][i] == '+'))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

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

int	main (int argc, char **argv)
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;
	int			i;

	if (argc == 1)
		return (0);
	if (integrity_check(argc, argv))
		exit_program(1, NULL, NULL);
	//init_stacks();
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_cdlstadd(&stack_a, ft_cdlstnew(ft_atol(argv[i]), i - 1,
						calculate_index(&stack_a, ft_atol(argv[i]), i)), 0))
			exit_program(1, &stack_a, &stack_b);
		i++;
	}
	ft_cdlstprint(stack_a);
	if (is_sorted(stack_a, stack_b))
		exit_program(0, &stack_a, &stack_b);
	sorting_algorithm(&stack_a, &stack_b);
	ft_cdlstprint(stack_a);
	exit_program(0, &stack_a, &stack_b);
}
