/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstring_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:52:02 by timtan            #+#    #+#             */
/*   Updated: 2025/08/26 15:48:56 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_adder(char **fstring, int flags)
{
	while ((!(**fstring >= '1' && **fstring <= '9')) && **fstring != 'X'
		&& (!(**fstring >= 'a' && **fstring <= 'z')) && **fstring != '%')
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
			break ;
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

static int	convert(t_properties fwp, char **fstring, va_list args)
{
	char	*str;

	if (**fstring == 'X')
		fwp.flags |= FLAG_XXX;
	if (**fstring == 'c')
		return (c_convert(va_arg(args, int), fwp));
	else if (**fstring == 's')
		str = s_convert(va_arg(args, char *), fwp);
	else if (**fstring == 'p')
		str = p_convert(va_arg(args, void *), fwp);
	else if (**fstring == 'd' || **fstring == 'i')
		str = d_convert(va_arg(args, int), fwp);
	else if (**fstring == 'u')
		str = u_convert(va_arg(args, unsigned int), fwp);
	else if (**fstring == 'x' || **fstring == 'X')
		str = x_convert(va_arg(args, unsigned int), fwp);
	else if (**fstring == '%')
		str = ft_strdup("%");
	else
		str = NULL;
	return (ft_printstr(str));
}

int	fstring_parser(char **fstring, va_list args)
{
	t_properties	fwp;
	int				bytes;

	fwp.precision = 1;
	fwp.width = 0;
	fwp.c = 0;
	fwp.flags = flag_adder(fstring, FLAG_RST);
	if (fwp.flags & FLAG_PCS)
		fwp.precision = calc_pcs(fstring);
	else if (**fstring >= '1' && **fstring <= '9')
		fwp.width = width_adder(&(fwp.flags), fstring, &(fwp.precision));
	if (fwp.flags & FLAG_PCS || fwp.flags & FLAG_MNS)
		fwp.flags &= ~FLAG_ZRO;
	bytes = convert(fwp, fstring, args);
	return (bytes);
}
