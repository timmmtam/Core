/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:57:23 by timtan            #+#    #+#             */
/*   Updated: 2025/08/12 20:53:09 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*copy_stash(char *stash)
{
	char	*str;
	int		i;

	str = malloc(BUFFER_SIZE);
	if (!str)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		str[i] = stash[i];
		i++;
	}
	return (str);
}

int	has_newline(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_str(char *s, char *stash)
{
	char	*str;
	ssize_t	i;
	ssize_t	str_len;

	i = -1;
	str_len = 0;
	while (s[str_len] != '\0' && s[str_len] != '\n')
		str_len++;
	if (has_newline(s))
		str_len += 1;
	str = malloc(str_len + 1);
	if (!str)
		return (free(s), NULL);
	while (i++ < str_len - 1)
		str[i] = s[i];
	str[i] = '\0';
	i = 0;
	while (s[str_len] != '\0')
		stash[i++] = s[str_len++];
	stash[i] = '\0';
	return (free(s), str);
}

char	*ft_strjoin(char *str, char *buffer, size_t buffer_len)
{
	size_t	str_len;
	size_t	i;
	char	*str_new;

	str_len = 0;
	while (str[str_len])
		str_len++;
	str_new = malloc(str_len + buffer_len + 1);
	if (!str_new)
		return (free(str), NULL);
	i = 0;
	while (i < str_len)
	{
		str_new[i] = str[i];
		i++;
	}
	i = 0;
	while (i < buffer_len)
		str_new[str_len++] = buffer[i++];
	str_new[str_len] = '\0';
	return (free(str), str_new);
}
