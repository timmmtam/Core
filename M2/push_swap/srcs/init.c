/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:39:20 by timtan            #+#    #+#             */
/*   Updated: 2026/01/25 17:55:07 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Assigns index to node */
static int	calculate_index(t_cdlist **lst, int n, int end)
{
	int			index;
	int			i;

	index = 0;
	i = 0;
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

/*
 * Checks whether input is a number and '+' or '-'
 * Checks for + and - in between numbers and consecutive + or -
 */
static int	number_check(int ac, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = 1;
		if ((str[i][0] >= '0' && str[i][0] <= '9') || str[i][0] == '-'
				|| str[i][0] == '+')
		{
			if ((str[i][0] == '-' || str[i][0] == '+')
					&& str[i][j] == 0)
				return (1);
			while (str[i][j] != '\0')
			{
				if (!(str[i][j] >= '0' && str[i][j] <= '9'))
					return (1);
				j++;
			}
		}
		else
			return (1);
		i++;
	}
	return (0);
}

/* Checks whether input is a single string or multiple arguments */
static char	**parse_input(char **str, int ac, char **av, int *flag)
{
	if (ac == 2)
	{
		if (*av[1] == 0)
			exit_program(1, NULL, NULL, NULL);
		str = ft_split(av[1], 32);
		if (!str)
			exit_program(1, NULL, NULL, NULL);
		while (str[*flag])
			(*flag)++;
	}
	else
		str = &av[1];
	if (number_check(ac, str))
	{
		if (*flag)
			exit_program(1, NULL, NULL, str);
		else
			exit_program(1, NULL, NULL, NULL);
	}
	return (str);
}

/*
 * Parse input and initialize the stack_a with the given arguments
 * Flag is used to determine whether the input is a string or not.
 * If it is, flag is used to count the number of arguments in the string.
 * Then, argc is modified to be the amount of numbers passed into the program.
*/
void	init_stacks(t_cdlist **stk_a, t_cdlist **stk_b, int ac, char **av)
{
	char	**str;
	int		flag;
	int		i;

	flag = 0;
	str = NULL;
	str = parse_input(str, ac, av, &flag);
	i = 0;
	if (flag)
		ac = flag + 1;
	while (i < ac - 1)
	{
		if (ft_cdlstadd(stk_a, ft_cdlstnew(ft_atol(str[i]), i,
					calculate_index(stk_a, ft_atol(str[i]), i)), 0))
			exit_program(1, stk_a, stk_b, NULL);
		i++;
	}
	if (flag)
		free_split(str);
}
