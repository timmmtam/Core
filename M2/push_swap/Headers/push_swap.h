/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:20:56 by timtan            #+#    #+#             */
/*   Updated: 2026/01/25 18:17:05 by timtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../my_libft/Headers/libft.h"

typedef struct s_cdlist
{
	long			n;
	int				p;
	int				i;
	int				moves;
	int				target_p;
	struct s_cdlist	*prev;
	struct s_cdlist	*next;
}					t_cdlist;

t_cdlist	*ft_cdlstnew(long n, int position, int index);
int			smallest_number(t_cdlist *stack, int stack_size);
int			ft_cdlstadd(t_cdlist **lst, t_cdlist *new, int front);
void		ft_cdlstclear(t_cdlist **lst);
void		free_split(char **str);
void		swap(t_cdlist **lst);
void		rotate(t_cdlist **lst);
void		r_rotate(t_cdlist **lst);
void		push(t_cdlist **lst, t_cdlist **lst2);
void		execute_move(char *str, t_cdlist **stack_a, t_cdlist **stack_b);
void		sort(t_cdlist **stack_a, t_cdlist **stack_b);
void		init_stacks(t_cdlist **stk_a, t_cdlist **stk_b, int ac, char **av);
void		push_to_b(t_cdlist **stack_a, t_cdlist **stack_b);
void		get_instructions(t_cdlist *stack_a, t_cdlist *stack_b, int ins[]);
void		exec_instruction(t_cdlist **stack_a, t_cdlist **stack_b, int ins[]);
int			is_sorted(t_cdlist *stack_a, t_cdlist *stack_b);
int			exit_program(int err, t_cdlist **lst, t_cdlist **lst2, char **str);

#endif
