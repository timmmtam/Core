/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstring_parser_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:31:03 by timtan            #+#    #+#             */
/*   Updated: 2025/07/09 19:50:58 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fstring_parser(char **fstring, va_list args)
{
	int		flag;

	flag = FLAG_RST;
	while (*fstring)
	{
		if (**fstring == '-')
			flag |= FLAG_MNS;
		else if (**fstring == '0')
			flag |= FLAG_ZRO;
		else if (**fstring == '.')
			flag |= FLAG_PCS;
		else if (**fstring == '#')
			flag |= FLAG_ALT;
		else if (**fstring == ' ')
			flag |= FLAG_SPC;
		else if (**fstring == '+')
			flag |= FLAG_POS;
		format++;
	}
}
