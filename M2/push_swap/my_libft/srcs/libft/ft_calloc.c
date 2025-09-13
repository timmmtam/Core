/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:03:54 by timtan            #+#    #+#             */
/*   Updated: 2025/05/27 21:04:33 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	return (ft_memset(array, 0, nmemb * size));
}
