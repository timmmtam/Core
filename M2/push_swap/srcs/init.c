/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:39:20 by timtan            #+#    #+#             */
/*   Updated: 2025/10/03 17:49:26 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Assigns index to node*/
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

/*Checks whether input is a number*/
static int	number_check(int ac, char **str)
{
	int	i;
	int	j;

	if (!str)
		return (1);
	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9') && !(str[i][j] == '-')
					&& !(str[i][j] == '+'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*Checks whether input is a single string or multiple arguments*/
static char	**parse_input(char **str, int ac, char **av, int *flag)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], 32);
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

/*Parse input and initialize the stack_a with the given arguments*/
void	init_stacks(t_cdlist **stack_a, t_cdlist **stack_b, int ac, char **av)
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
		if (ft_cdlstadd(stack_a, ft_cdlstnew(ft_atol(str[i]), i,
					calculate_index(stack_a, ft_atol(str[i]), i)), 0))
			exit_program(1, stack_a, stack_b, NULL);
		i++;
	}
	if (flag)
		free_split(str);
}
