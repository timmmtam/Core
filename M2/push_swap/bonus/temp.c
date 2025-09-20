/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:06:26 by timtan            #+#    #+#             */
/*   Updated: 2025/09/20 19:06:39 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	integrity_check(int ac, char **av)
{
	int	j;

	j = 1;
	while (i < ac)
	{
		if (ft_strncmp(av[j], "pa", 3) || ft_strncmp(av[j], "pb", 3))
			return (1);
		if (ft_strncmp(av[j], "ra", 3) || ft_strncmp(av[j], "rb", 3))
			return (1);
		if (ft_strncmp(av[j], "rra", 4) || ft_strncmp(av[j], "rrb", 4))
			return (1);
		if (ft_strncmp(av[j], "rr", 3) || ft_strncmp(av[j], "rrr", 4))
			return (1);
		if (ft_strncmp(av[j], "sa", 3) || ft_strncmp(av[j], "sb", 3))
			return (1);
		if (ft_strncmp(av[j], "ss", 3))
			return (1);
	}
	return (0);
}
