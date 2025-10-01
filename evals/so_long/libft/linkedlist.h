/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sming-zh <sming-zh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:05:35 by sming-zh          #+#    #+#             */
/*   Updated: 2025/09/07 16:19:19 by sming-zh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_at(t_list **lst, t_list *new, int index);
t_list	*ft_lstnode_at(t_list *lst, int index);
void	ft_lstdelone_at(t_list **lst, void (*del)(void *), int index);
t_list	*ft_lstdup(t_list *lst, void *(*dup_content)(void *));

typedef struct s_dlist
{
	struct s_dlist	*prev;
	void			*content;
	struct s_dlist	*next;
}	t_dlist;

t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
int		ft_dlstsize(t_dlist *dlst);
t_dlist	*ft_dlstlast(t_dlist *dlst);
void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *));
void	ft_dlstclear(t_dlist **dlst, void (*del)(void *));
void	ft_dlstadd_at(t_dlist **dlst, t_dlist *new, int index);
t_dlist	*ft_dlstnode_at(t_dlist *dlst, int index);

#endif
