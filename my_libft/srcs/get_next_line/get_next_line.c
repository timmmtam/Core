/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:33:49 by timtan            #+#    #+#             */
/*   Updated: 2025/09/13 17:59:23 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[FD_SIZE][BUFFER_SIZE];
	ssize_t		read_bytes;
	char		*str;

	if (fd < 0 || fd >= FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	str = copy_stash(stash[fd]);
	if (!str)
		return (NULL);
	while (!has_newline(str))
	{
		read_bytes = read(fd, stash[fd], BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		str = gnl_strjoin(str, stash[fd], read_bytes);
		if (!str)
			return (NULL);
	}
	str = extract_str(str, stash[fd]);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
		return (free(str), NULL);
	return (str);
}
