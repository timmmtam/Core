/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:20:56 by timtan            #+#    #+#             */
/*   Updated: 2025/09/23 19:45:49 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../my_libft/Headers/libft.h"

typedef struct s_cdlist
{
	long	n;
	int		p;
	int		i;
	struct s_cdlist *prev;
	struct s_cdlist *next;
}					t_cdlist;

t_cdlist	*ft_cdlstnew(long n ,int position, int index);
int			ft_cdlstadd(t_cdlist **lst, t_cdlist *new, int front);
void		ft_cdlstclear(t_cdlist **lst);
void		ft_cdlstprint(t_cdlist *lst);
void		ft_cdlstprintone(t_cdlist *node);
void		swap(t_cdlist **lst);
void		rotate(t_cdlist **lst);
void		r_rotate(t_cdlist **lst);
void		push(t_cdlist **lst, t_cdlist **lst2);
void		execute_move(char *str, t_cdlist **stack_a, t_cdlist **stack_b);
void		sorting_algorithm(t_cdlist **stack_a, t_cdlist **stack_b);
int			exit_program(int error, t_cdlist **lst, t_cdlist **lst2);

#endif
