/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:49:42 by timtan            #+#    #+#             */
/*   Updated: 2025/06/06 21:46:58 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

/*void	del_content(void *content)
{
	if (!content)
		return ;
	free(content);
	printf("yay\n");
}

int	main(void)
{
	t_list	*node = malloc(sizeof(t_list));

	node -> content = malloc(sizeof(int));
	*((int *)node->content) = 42;
	ft_lstdelone(node, del_content);
}*/
