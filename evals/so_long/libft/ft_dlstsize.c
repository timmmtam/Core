/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:43:34 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/22 12:53:12 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

int	ft_dlstsize(t_dlist *dlst)
{
	int		count;

	if (dlst == NULL)
		return (0);
	count = 1;
	while (dlst->next)
	{
		dlst = dlst->next;
		count++;
	}
	return (count);
}
