/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:01:47 by sming-zh          #+#    #+#             */
/*   Updated: 2025/05/19 14:01:49 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	start_index(char const *s1, char const *set)
{
	int		index;
	char	*set1;

	index = 0;
	while (s1[index])
	{
		set1 = (char *) set;
		while (*set1 && s1[index] != *set1)
			set1++;
		if (!*set1)
			break ;
		index++;
	}
	return (index);
}

static int	end_index(char const *s1, char const *set)
{
	int		index;
	char	*set1;

	index = ft_strlen(s1) - 1;
	while (index >= 0)
	{
		set1 = (char *) set;
		while (*set1 && s1[index] != *set1)
			set1++;
		if (!*set1)
			break ;
		index--;
	}
	return (index);
}

static char	*empty_string(void)
{
	char	*empty;

	empty = (char *) malloc(1);
	if (empty)
		empty[0] = '\0';
	return (empty);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		index;
	int		write_length;
	char	*str;

	start = start_index(s1, set);
	if (start == (int) ft_strlen(s1))
		return (empty_string());
	end = end_index(s1, set);
	write_length = end - start + 1;
	str = (char *) malloc(write_length + 1);
	if (str)
	{
		index = 0;
		while (index < write_length)
		{
			str[index] = s1[start];
			start++;
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
