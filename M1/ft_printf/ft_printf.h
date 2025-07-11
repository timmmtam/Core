/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:32:58 by timtan            #+#    #+#             */
/*   Updated: 2025/07/11 18:30:23 by timtan           ###   ########.fr       */
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

int	ft_printf(const char *, ...);

#endif
