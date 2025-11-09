/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:20:56 by timtan            #+#    #+#             */
/*   Updated: 2025/11/09 21:44:20 by timtan           ###   ########.fr       */
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
	int		moves;
	int		target_p;
	struct s_cdlist *prev;
	struct s_cdlist *next;
}					t_cdlist;

t_cdlist	*ft_cdlstnew(long n ,int position, int index);
int			ft_cdlstadd(t_cdlist **lst, t_cdlist *new, int front);
void		ft_cdlstclear(t_cdlist **lst);
void		ft_cdlstprint(t_cdlist *lst);
void		ft_cdlstprintone(t_cdlist *node);
void		free_split(char **str);
void		swap(t_cdlist **lst);
void		rotate(t_cdlist **lst);
void		r_rotate(t_cdlist **lst);
void		push(t_cdlist **lst, t_cdlist **lst2);
void		execute_move(char *str, t_cdlist **stack_a, t_cdlist **stack_b);
void		sorting_algorithm(t_cdlist **stack_a, t_cdlist **stack_b);
void		init_stacks(t_cdlist **stack_a, t_cdlist **stack_b, int ac, char **av);
void		push_to_b(t_cdlist **stack_a, t_cdlist **stack_b);
void		execute_cheapest(t_cdlist **stack_a, t_cdlist **stack_b);
int			is_sorted(t_cdlist *stack_a, t_cdlist *stack_b);
int			exit_program(int error, t_cdlist **lst, t_cdlist **lst2, char **str);

#endif
