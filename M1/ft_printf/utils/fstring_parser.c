/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstring_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:52:02 by timtan            #+#    #+#             */
/*   Updated: 2025/07/18 18:53:25 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_adder(char **fstring, int flags)
{
	while (**fstring != '\0')
	{
		while (**fstring <= '0' && >= '9')
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
			**fstring++;
		}
		if (**fstring >= '0' && **fstring <= '9')
			while (**fstring <= 'a' && >= 'z' && != 0)
			{
				if (flags & FLAG_PCS)
				{
					precision ();
	}
}

int	width_adder(char *fstring)
{

}

int	fstring_parser(char **fstring, va_list args)
{
	ssize_t	precision;
	ssize_t	width;
	int		flags;

	precision = 1;
	width = 0;
	flags = FLAG_RST;
	while (**fstring >= 'a' && **fstring <= 'z' && **fstring != 0)
	{
		flags = flag_adder(&*fstring, flags);

}
