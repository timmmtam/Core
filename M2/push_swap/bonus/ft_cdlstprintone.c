/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstprintone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:11:56 by timtan            #+#    #+#             */
/*   Updated: 2025/09/18 19:16:48 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cdlstprintone(t_cdlist *node)
{
	ft_printf("n = %d, p = %d, i = %d\n", node->n, node->p, node->i);
	return ;
}
