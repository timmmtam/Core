/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:18:57 by timtan            #+#    #+#             */
/*   Updated: 2025/06/18 22:33:27 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	buf_i;
	static ssize_t	read_bytes;
	char			*str;
	ssize_t			newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf_i == read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buf_i = 0;
	}
	str = malloc(1);
	str[0] = '\0';
	newline_pos = find_newline(buffer, read_bytes, buf_i);
	while (newline_pos < 0)
	{
		str = ft_strjoin(str, make_buffer(buffer, &buf_i, -newline_pos));
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buf_i = 0;
		newline_pos = find_newline(buffer, read_bytes, buf_i);
	}
	return (ft_strjoin(str, make_buffer(buffer, &buf_i, newline_pos)));
}
