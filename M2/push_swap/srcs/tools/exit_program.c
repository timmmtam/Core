/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:10:18 by timtan            #+#    #+#             */
/*   Updated: 2026/02/09 10:10:38 by timtan           ###   ########.fr       */
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
