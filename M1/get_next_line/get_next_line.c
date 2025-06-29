/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:33:49 by timtan            #+#    #+#             */
/*   Updated: 2025/06/30 01:27:53 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	 static char	*stash[FD_SIZE];
	 ssize_t		read_bytes;
	 char			buffer[BUFFER_SIZE];
	 char			*str_to_return;

	if (fd < 0 || fd >= FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	while (!has_newline(&stash[fd]))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		stash[fd] = ft_strjoin(stash[fd], buffer, read_bytes);
		if (!stash[fd])
			return (NULL);
		buffer_reset(buffer);
	}
	str_to_return = take_from_stash(stash, fd);
	if (str_to_return[0] == '\0')
		return (NULL);
	return (str_to_return);
}
