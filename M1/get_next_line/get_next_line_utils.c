/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:57:23 by timtan            #+#    #+#             */
/*   Updated: 2025/08/03 19:27:20 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	newline_or_null(char **stash, int fd)
{
	size_t	len;

	len = 0;
	while (stash[fd][len] != '\0')
	{
		if (stash[fd][len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	return (len);
}

static char	*my_strcpy(char *s1, size_t start)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[start + len] != '\0')
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

int	has_newline(char **str)
{
	ssize_t	i;

	if (!*str)
	{
		*str = malloc(1);
		if (!*str)
			return (-1);
		*str[0] = '\0';
		return (0);
	}
	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*take_from_stash(char **stash, int fd)
{
	size_t	len;
	size_t	i;
	char	*temp_stash;
	char	*str;

	if (!stash[fd])
		return (NULL);
	len = newline_or_null(stash, fd);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = stash[fd][i];
		i++;
	}
	str[i] = '\0';
	temp_stash = my_strcpy(stash[fd], len);
	free(stash[fd]);
	stash[fd] = temp_stash;
	return (str);
}

char	*ft_strjoin(char *stash, char *buffer, size_t buffer_len)
{
	size_t	stash_len;
	size_t	i;
	char	*str_new;

	stash_len = 0;
	while (stash[stash_len])
		stash_len++;
	str_new = malloc(stash_len + buffer_len + 1);
	if (!str_new)
		return (free (stash), NULL);
	i = 0;
	while (i < stash_len)
	{
		str_new[i] = stash[i];
		i++;
	}
	i = 0;
	while (i < buffer_len)
		str_new[stash_len++] = buffer[i++];
	str_new[stash_len] = '\0';
	return (free (stash), str_new);
}
