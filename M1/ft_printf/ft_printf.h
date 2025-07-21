/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:32:58 by timtan            #+#    #+#             */
/*   Updated: 2025/07/21 20:22:13 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define FLAG_RST 0b00000000
# define FLAG_MNS 0b00000001
# define FLAG_ZRO 0b00000010
# define FLAG_ALT 0b00000100
# define FLAG_POS 0b00001000
# define FLAG_SPC 0b00010000
# define FLAG_PCS 0b00100000
# define FLAG_XXX 0b01000000

typedef struct
{
	int	flags;
	ssize_t	width;
	ssize_t	precision;
} fwp;

int		ft_printf(const char *, ...);
char	*c_convert(char c, int flags, ssize_t width);
char	*s_convert(char *s, int flags, ssize_t width, char *fstring);
char	*p_convert(void *p, int flags, ssize_t width);
char	*d_convert(int n, int flags, ssize_t width, char *fstring);
char	*u_convert(unsigned int n, int flags, ssize_t width, char *fstring);
char	*x_convert(unsigned int n, int flags, ssize_t width, char *fstring);
char	*pcs_check(int flags, char *fstring, ssize_t buf_len);
char	*width_check(int flags, int width, char *str);
char	*alt_check(int flags);
char	*ft_itoa(int n);
char	*ft_uinttoa(unsigned int n);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_revstr(char	*str);
ssize_t	ft_strlen(char *str);
ssize_t	precision(int flags, char *fstring);

#endif
