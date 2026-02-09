/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:23:47 by timtan            #+#    #+#             */
/*   Updated: 2026/02/09 10:46:31 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execute_move_2(char *str, t_cdlist **stack_a, t_cdlist **stack_b)
{
	if (!ft_strncmp(str, "ss\n", 3))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strncmp(str, "rr\n", 3))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strncmp(str, "rrr\n", 4))
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
	else
		return (0);
	return (1);
}

static int	execute_move_1(char *str, t_cdlist **stack_a, t_cdlist **stack_b)
{
	if (!stack_a && !stack_b)
		return (0);
	if (!ft_strncmp(str, "sa\n", 3))
		swap(stack_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap(stack_b);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate(stack_a);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(stack_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		r_rotate(stack_a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		r_rotate(stack_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb\n", 3))
		push(stack_a, stack_b);
	else
		return (execute_move_2(str, stack_a, stack_b));
	return (1);
}

static void	read_instructions(t_cdlist **stack_a, t_cdlist **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_move_1(line, stack_a, stack_b))
		{
			free(line);
			exit_program(1, stack_a, stack_b, NULL);
		}
		free(line);
		line = get_next_line(0);
	}
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
	read_instructions(&stack_a, &stack_b);
	if (is_sorted(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit_program(0, &stack_a, &stack_b, NULL);
}
