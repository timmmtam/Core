# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 18:30:48 by timtan            #+#    #+#              #
#    Updated: 2025/09/18 19:23:05 by timtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -IHeaders

OBJDIR = objs

VPATH = srcs:srcs/operations:srcs/tools

SRCS =	push_swap.c	ft_cdlstnew.c	ft_cdlstadd.c	ft_cdlstclear.c \
		swap.c		ft_cdlstprint.c	rotate.c		ft_cdlstprintone.c \
		push.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

all: build_libft $(NAME)

build_libft:
	$(MAKE) -C my_libft

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) my_libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C my_libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all build_libft clean fclean re
