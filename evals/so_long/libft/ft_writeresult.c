/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeresult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:14:42 by sming-zh          #+#    #+#             */
/*   Updated: 2025/06/17 15:14:43 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	write_result(int result, int *var)
{
	if (*var == -1)
		return (-1);
	if (result == -1)
	{
		*var = -1;
		return (-1);
	}
	*var += result;
	return (result);
}
