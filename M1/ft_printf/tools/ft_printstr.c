/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:55:29 by timtan            #+#    #+#             */
/*   Updated: 2025/07/31 21:24:37 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nullcase(properties fwp)
{
	if (fwp.flags & FLAG_PCS)
	{
		if (fwp.precision > 5)
		{
			write(1, "(null)", 6);
			return (6);
		}
		else
			return (0);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}

int	ft_printstr(char *s, properties fwp)
{
	int	i;

	i = 0;
	if (!s)
		return (nullcase(fwp));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	free(s);
	if (fwp.c == 1)
		i += 1;
	return (i);
}
