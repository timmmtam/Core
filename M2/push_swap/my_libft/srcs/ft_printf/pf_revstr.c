/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:50:30 by timtan            #+#    #+#             */
/*   Updated: 2025/09/13 18:14:26 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_revstr(char *str)
{
	char	tmp;
	size_t	str_len;
	size_t	i;

	if (!str)
		return (NULL);
	str_len = 0;
	i = 0;
	while (str[str_len])
		str_len++;
	while (i < str_len - 1)
	{
		tmp = str[i];
		str[i] = str[str_len - 1];
		str[str_len - 1] = tmp;
		i++;
		str_len--;
	}
	return (str);
}
