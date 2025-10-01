/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:51:46 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/01 19:27:04 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

char	*ft_strjoin(const char *head, const char *tail)
{
	char	*new;
	int		new_i;

	new = malloc(ft_strlen(head) + ft_strlen(tail) + 1);
	if (!new)
		return (NULL);
	new_i = 0;
	while (*head)
		new[new_i++] = *head++;
	while (*tail)
		new[new_i++] = *tail++;
	new[new_i] = '\0';
	return (new);
}

/**
 * Performs ft_strjoin but frees the head after.
 */
char	*ft_strjoinfree(char *head, const char *tail)
{
	char	*new;

	new = ft_strjoin(head, tail);
	free(head);
	return (new);
}
