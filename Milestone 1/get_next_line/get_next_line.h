/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:17:29 by timtan            #+#    #+#             */
/*   Updated: 2025/06/18 22:15:27 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> /* for read*/
# include <stdlib.h> /* for malloc */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
ssize_t	find_newline(char *buffer, ssize_t read_bytes, ssize_t buf_i);
char	*make_buffer(char *buffer, ssize_t *buf_i, ssize_t newline_pos);
char	*expand_buf(char *buf, char *buf_add);

#endif
