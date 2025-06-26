/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:55:39 by timtan            #+#    #+#             */
/*   Updated: 2025/06/24 19:06:18 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef FD_SIZE
#  define FD_SIZE 20
# endif

char	*get_next_line(int fd);
int		has_newline(char *str);
char	*ft_strjoin(char *str, char *str2);
char	*create_stash(char ***buffer, int fd, ssize_t read_bytes);

#endif
