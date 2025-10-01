/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:19:17 by sming-zh          #+#    #+#             */
/*   Updated: 2025/07/25 15:27:29 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

static ssize_t	read_line(int fd, char **leftover)
{
	ssize_t		bytes;
	char		*buffer;
	char		*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(*leftover, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		if (*leftover)
		{
			temp = *leftover;
			*leftover = ft_strjoin(*leftover, buffer);
			free(temp);
		}
		else
			*leftover = ft_strdup(buffer);
	}
	free(buffer);
	return (bytes);
}

static char	*extract_line(char *str)
{
	char	*nl;

	if (!str || !*str)
		return (NULL);
	nl = ft_strchr(str, '\n');
	if (nl)
		return (ft_substr(str, 0, nl - str + 1));
	return (ft_strdup(str));
}

static void	trim_leftover(char **leftover)
{
	char	*nl;
	char	*temp;

	nl = ft_strchr(*leftover, '\n');
	if (nl && ft_strlen(nl) > 1)
	{
		temp = *leftover;
		*leftover = \
ft_substr(*leftover, nl - *leftover + 1, ft_strlen(*leftover));
		free(temp);
	}
	else
	{
		free(*leftover);
		*leftover = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*leftover[1024];
	char		*line;

	if (fd < 0)
		return (NULL);
	read_line(fd, &leftover[fd]);
	line = extract_line(leftover[fd]);
	trim_leftover(&leftover[fd]);
	return (line);
}
