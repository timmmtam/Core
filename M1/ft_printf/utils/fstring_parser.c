/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstring_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:52:02 by timtan            #+#    #+#             */
/*   Updated: 2025/07/23 19:53:45 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_adder(char **fstring, int flags)
{
	while (**fstring <= '1' && **fstring>= '9' && 
			**fstring <= 'a' && **fstring >= 'z')
	{
		if (**fstring == '-')
			flag |= FLAG_MNS;
		else if (**fstring == '0')
			flag |= FLAG_ZRO;
		else if (**fstring == '#')
			flag |= FLAG_ALT;
		else if (**fstring == ' ')
			flag |= FLAG_SPC;
		else if (**fstring == '+')
			flag |= FLAG_POS;
		else if (**fstring == '.')
		{
			flags |= FLAG_PCS;
			*fstring++;
			return (flags);
		}
		*fstring++;
	}
	return (flags);
}

static int	width_adder(int flags, char **fstring, ssize_t *precision)
{
	int	width;

	width = 0;
	while (**fstring >= '1' && **fstring <= '9')
	{
		width = width * 10 + (**fstring - '0');
		*fstring++;
	}
	if (**fstring == '.')
	{
		flags |= FLAG_PCS;
		*fstring++;
		*precision = precision(flags, fstring);
	}
	return (width);
}

static ssize_t	precision(int flags, char **fstring)
{
	ssize_t	precision;

	precision = 0;
	while (**fstring >= '0' && **fstring <= '9')
	{
		precision = precision * 10 + (**fstring - '0');
		*fstring++;
	}
	return (precision);
}

static int	convert(fwp fwp, char **fstring, va_list args)
{
	char	*str;

	if (**fstring == 'X')
		fwp->flags |= FLAG_XXX;
	if (**fstring == 'c')
		str = c_convert(va_arg(args, int), fwp);
	else if (**fstring == 's')
		str = s_convert(va_arg(args, char*), fwp);
	else if (**fstring == 'p')
		str = p_convert(va_arg(args, void*), fwp);
	else if (**fstring == 'd' || **fstring == 'i')
		str = d_convert(va_arg(args, int), fwp);
	else if (**fstring == 'u')
		str = u_convert(va_arg(args, unsigned int), fwp);
	else if (**fstring == 'x' || **fstring == 'X')
		str = x_convert(va_arg(args, unsigned int), fwp);
	else if (**fstring == '%')
		str = "%";
	else
		str = NULL;
	print_str(str);
	return ((int)ft_strlen(str));
}

int	fstring_parser(char **fstring, va_list args)
{
	fwp	fwp;

	fwp->precision = 1;
	fwp->width = 0;
	fwp->flags = flag_adder(fstring, FLAG_RST);
	if ((fwp->flags & FLAG_PCS) && **fstring >= '0' && **fstring <= '9')
		fwp->precision = precision(flags, fstring);
	else if (**fstring >= '1' **fstring <= '9')
		fwp->width = width_adder(flags, fstring, &precision);
	if (fwp->flags & FLAG_PCS || fwp->flags & FLAGS_MNS)
		fwp->flags & ~FLAG_ZRO;
	return (convert(fwp, fstring, args));
}
