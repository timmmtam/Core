# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 18:30:48 by timtan            #+#    #+#              #
#    Updated: 2026/02/09 11:00:14 by timtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

CFLAGS = -Wall -Wextra -Werror -IHeaders

OBJDIR = objs

VPATH = srcs:srcs/operations:srcs/tools:srcs/sorting:bonus

SRCS =	main.c			ft_cdlstnew.c		ft_cdlstadd.c	ft_cdlstclear.c \
		swap.c			rotate.c			push.c			sort.c \
		init.c			execute.c			free_split.c	push_to_b.c \
		is_sorted.c		smallest_number.c	get_instructions.c \
		execute_instruction.c				exit_program.c

BONUS_SRCS =	main_bonus.c	ft_cdlstnew.c	ft_cdlstadd.c	ft_cdlstclear.c\
				swap.c			rotate.c		push.c			init.c \
				free_split.c	is_sorted.c		exit_program.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

BONUS_OBJS = $(addprefix $(OBJDIR)/, $(BONUS_SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

all: build_libft $(NAME)

build_libft:
	$(MAKE) -C libft

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

bonus: build_libft $(BONUS_OBJS)
	cc $(CFLAGS) $(BONUS_OBJS) libft/libft.a -o $(BONUS_NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all build_libft clean fclean re bonus
