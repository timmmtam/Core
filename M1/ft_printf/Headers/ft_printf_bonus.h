/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:32:58 by timtan            #+#    #+#             */
/*   Updated: 2025/08/26 20:28:22 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

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
# define FLAG_NEG 0b10000000

typedef struct s_properties
{
	int		flags;
	int		c;
	ssize_t	width;
	ssize_t	precision;
}			t_properties;

int		ft_printf(const char *format, ...);
int		fstring_parser(char **fstring, va_list args);
int		c_convert(char c, t_properties fwp);
char	*s_convert(char *s, t_properties fwp);
char	*p_convert(void *p, t_properties fwp);
char	*d_convert(int n, t_properties fwp);
char	*u_convert(unsigned int n, t_properties fwp);
char	*x_convert(unsigned int n, t_properties fwp);
char	*pcs_check(ssize_t n, ssize_t buf_len, t_properties fwp);
char	*width_check(int flags, int width, char *str);
char	*alt_check(int flags, unsigned int n);
char	*ft_itoa(int n);
char	*ft_uinttoa(unsigned int n);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_revstr(char	*str);
char	*ft_strdup(char *s);
int		ft_printstr(char *s);
ssize_t	ft_strlen(char *str);

#endif
