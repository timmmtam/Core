/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:30:28 by timtan            #+#    #+#             */
/*   Updated: 2025/06/18 22:20:15 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*void	read_fd(int fd, char **buffer, size_t BUFFER_SIZE, ssize_t *buf_i)
{
	ssize_t read_bytes;
	read_bytes = read(fd, *buffer, BUFFER_SIZE)
	if (read_bytes = 0)
		return (NULL);
	if (read_bytes = -1)
*/

ssize_t	find_newline(char *buffer, ssize_t read_bytes, ssize_t buf_i)
{
	while (buf_i < read_bytes)
	{
		if (buffer[buf_i] == '\n')
			return (buf_i);
		buf_i++;
	}
	return (-(buf_i - 1));
}

char	*make_buffer(char *buffer, ssize_t *buf_i, ssize_t newline_pos)
{
	int		i;
	char	*new_buffer;

	new_buffer = malloc(newline_pos - *buf_i + 2);
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (*buf_i <= newline_pos)
	{
		new_buffer[i] = buffer[*buf_i];
		i++;
		(*buf_i)++;
	}
	new_buffer[i] = '\0';
	return (new_buffer);
}

char	*ft_strjoin(char *str, char *str_add)
{
	size_t	str_len;
	size_t	str_add_len;
	size_t	i;
	char	*new_str;

	str_len = 0;
	while (str[str_len])
		str_len++;
	str_add_len = 0;
	while (str_add[str_add_len])
		str_add_len++;
	new_str = malloc(str_len + str_add_len + 1);
	if (!new_str)
		return (free(str), free(str_add), NULL);
	i = 0;
	while (i < str_len)
	{
		new_str[i] = str[i];
		i++;
	}
	str_add_len = 0;
	while (str_add[str_add_len])
		new_str[i++] = str_add[str_add_len++];
	new_str[i] = '\0';
	return (free(str), free(str_add), new_str);
}
