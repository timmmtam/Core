/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:55:39 by timtan            #+#    #+#             */
/*   Updated: 2025/08/03 19:30:44 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef FD_SIZE
#  define FD_SIZE 100
# endif

char	*get_next_line(int fd);
int		has_newline(char **str);
char	*take_from_stash(char **stash, int fd);
char	*ft_strjoin(char *stash, char *buffer, size_t buffer_len);

#endif
