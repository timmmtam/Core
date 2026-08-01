/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:55:39 by timtan            #+#    #+#             */
/*   Updated: 2025/08/12 20:30:33 by timtan           ###   ########.fr       */
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
#  define FD_SIZE 100
# endif

char	*get_next_line(int fd);
int		has_newline(char *str);
char	*extract_str(char *s, char *stash);
char	*ft_strjoin(char *str, char *buffer, size_t buffer_len);
char	*copy_stash(char *stash);

#endif
