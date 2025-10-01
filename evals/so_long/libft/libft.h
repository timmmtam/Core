/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:56:24 by sming-zh          #+#    #+#             */
/*   Updated: 2025/08/31 17:11:12 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "linkedlist.h"
# include <stddef.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *head, char const *tail);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// Modified libft functions

int		ft_putnbr_fd(long n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putstrn_fd(char *str, int len, int fd);
int		ft_putendl_fd(char *s, int fd);

// get_next_line
char	*get_next_line(int fd);

// ft_printf
int		ft_printf(const char *str, ...);
int		ft_printf_fd(int fd, const char *str, ...);

// Non standard libft functions

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;
size_t	ft_charcount(const char *str, unsigned char c);
size_t	ft_strcount(const char *big, const char *little);
char	*ft_strreplace(const char *str, const char *from, const char *to);
char	*ft_convert_base(unsigned long n, const char *base);
t_uint	ft_numlen(long l);
char	*ft_uitoa(unsigned int u);
char	*ft_ltoa(long n);
char	*ft_strtolower(char *str);
char	*ft_strtoupper(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strstr(const char *big, const char *little);
ssize_t	ft_math_min(ssize_t a, ssize_t b);
ssize_t	ft_math_max(ssize_t a, ssize_t b);
ssize_t	ft_putcharrepeat(char c, int amount);
long	ft_abs(long n);
int		write_result(int result, int *var);
char	*ft_strjoinfree(char *head, const char *tail);
void	ft_freestrarray(char **str);
char	*ft_strelement(const char *str, char deli, int index);
char	*ft_strarray_join(const char **array, char deli);
long	ft_atol(const char *str);
int		ft_strisnum(const char *str);
int		ft_strarray_size(const char **array);
int		ft_strstartswith(const char *str, const char *prefix);
int		ft_strendswith(const char *str, const char *suffix);
char	**ft_strarrdup(const char **arr);

#endif