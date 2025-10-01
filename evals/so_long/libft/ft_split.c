/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:16:59 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/01 16:29:13 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	word_count(char const *s, char c)
{
	int	index;
	int	count;

	index = 0;
	while (s[index] && s[index] == c)
		index++;
	if (!*s)
		return (0);
	count = 1;
	while (s[index])
	{
		if ((index > 0 && s[index - 1] == c) && s[index] != c)
			count++;
		index++;
	}
	return (count);
}

static int	has_failed(char *str, char **array, int computed_index)
{
	int	index;

	if (!str)
	{
		index = 0;
		while (index <= computed_index)
		{
			free(array[index]);
			index++;
		}
		free(array);
		return (1);
	}
	return (0);
}

static char	**handle_split(char **ptr, int ptr_size, char const *s, char c)
{
	int	end_index;
	int	array_index;
	int	sub_index;

	array_index = 0;
	while (array_index < ptr_size)
	{
		while (*s == c)
			s++;
		end_index = 0;
		while (s[end_index] && s[end_index] != c)
			end_index++;
		ptr[array_index] = (char *) malloc(end_index + 1);
		if (has_failed(ptr[array_index], ptr, array_index))
			return (NULL);
		sub_index = 0;
		while (sub_index < end_index)
		{
			ptr[array_index][sub_index] = s[sub_index];
			sub_index++;
		}
		ptr[array_index++][sub_index] = '\0';
		s += end_index + 1;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;

	if (ft_strlen(s) == 0)
		return (NULL);
	while (*s && *s == c)
		s++;
	words = word_count(s, c);
	if (words == 0)
		return (NULL);
	split = (char **) malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[words] = NULL;
	return (handle_split(split, words, s, c));
}
