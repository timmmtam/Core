/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:33:49 by timtan            #+#    #+#             */
/*   Updated: 2025/06/25 04:23:29 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	 static char	buffer[FD_SIZE][BUFFER_SIZE];
	 ssize_t		read_bytes;
	 char			*stash;
	 char			**initial_address;

	 initial_address = buffer;
	 read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
	 if (read_bytes <= 0)
		 return (NULL);
	 stash = create_stash(&buffer, fd, read_bytes);
	 while (!has_newline(stash))
	 {
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		stash = ft_strjoin(stash, create_stash(&buffer, fd, read_bytes);
	 }
	 return (stash);
}
