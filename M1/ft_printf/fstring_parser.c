/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstring_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:52:02 by timtan            #+#    #+#             */
/*   Updated: 2025/07/24 21:35:39 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_adder(char **fstring, int flags)
{
	while ((!(**fstring >= '1' && **fstring<= '9')) && 
			(!(**fstring >= 'a' && **fstring <= 'z')))
	{
		if (**fstring == '-')
			flags |= FLAG_MNS;
		else if (**fstring == '0')
			flags |= FLAG_ZRO;
		else if (**fstring == '#')
			flags |= FLAG_ALT;
		else if (**fstring == ' ')
			flags |= FLAG_SPC;
		else if (**fstring == '+')
			flags |= FLAG_POS;
		else if (**fstring == '.')
		{
			flags |= FLAG_PCS;
			(*fstring)++;
			return (flags);
		}
		(*fstring)++;
	}
	return (flags);
}

static ssize_t	calc_pcs(char **fstring)
{
	ssize_t	precision;

	precision = 0;
	while (**fstring >= '0' && **fstring <= '9')
	{
		precision = precision * 10 + (**fstring - '0');
		(*fstring)++;
	}
	return (precision);
}

static ssize_t	width_adder(int *flags, char **fstring, ssize_t *precision)
{
	ssize_t	width;

	width = 0;
	while (**fstring >= '0' && **fstring <= '9')
	{
		width = width * 10 + (**fstring - '0');
		(*fstring)++;
	}
	if (**fstring == '.')
	{
		*flags |= FLAG_PCS;
		(*fstring)++;
		*precision = calc_pcs(fstring);
	}
	return (width);
}

static int	convert(properties fwp, char **fstring, va_list args)
{
	char	*str;

	if (**fstring == 'X')
		fwp.flags |= FLAG_XXX;
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
	ft_printstr(str);
	return ((int)ft_strlen(str));
}

int	fstring_parser(char **fstring, va_list args)
{
	properties	fwp;

	fwp.precision = 1;
	fwp.width = 0;
	fwp.flags = flag_adder(fstring, FLAG_RST);
	if ((fwp.flags & FLAG_PCS) && **fstring >= '0' && **fstring <= '9')
		fwp.precision = calc_pcs(fstring);
	else if (**fstring >= '1' && **fstring <= '9')
		fwp.width = width_adder(&(fwp.flags), fstring, &(fwp.precision));
	if (fwp.flags & FLAG_PCS || fwp.flags & FLAG_MNS)
		fwp.flags &= ~FLAG_ZRO;
	return (convert(fwp, fstring, args));
}
