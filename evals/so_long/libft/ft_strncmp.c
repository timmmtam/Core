/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:18:53 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/19 11:18:54 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			iter;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	iter = 0;
	while (iter < n)
	{
		if (!*us1 || !*us2)
			break ;
		if (*us1 != *us2)
			break ;
		us1++;
		us2++;
		iter++;
	}
	if (iter == n)
		return (0);
	return (*us1 - *us2);
}
