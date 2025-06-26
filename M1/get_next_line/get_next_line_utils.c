/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:57:23 by timtan            #+#    #+#             */
/*   Updated: 2025/06/25 04:23:29 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		has_newline(char *str)
{
	ssize_t i;

	i = 0;
	while (str)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *str2)
{
	size_t	str_len;
	size_t	str2_len;
	size_t	i;
	char	*str_new;

	str_len = 0;
	str2_len = 0;
	while (str[str_len])
		str_len++;
	while (str2[str2_len])
		str2_len++;
	str_new = malloc(str_len + str2_len + 1);
	if (!str_new)
		return (free (str), free (str2), NULL);
	i = 0;
	while (i < str_len)
	{
		str_new[i] = str[i];
		i++;
	}
	i = 0;
	while (i < str2_len)
		str_new[str_len++] = str2[i++];
	str_new[str_len] = '\0';
	return (free (str), free (str2), str_new);
}

char	*create_stash(char ***buffer, int fd, ssize_t read_bytes)
{
	char	*str;
	size_t	buf_len;
	size_t	i;

	buf_len = 0;
	while (*(buffer[fd][buf_len]) != '\n' && buf_len < read_bytes)
		buf_len++;
	str = malloc(buf_len + 1);
	i = 0;
	while (i < buf_len)
	{
		str[i] = *buffer[fd]++;
		if (str[i++] == '\n')
			break;
	}
	str[i] = '\0';
	return (str);
}
