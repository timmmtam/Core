# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 18:30:48 by timtan            #+#    #+#              #
#    Updated: 2026/01/29 12:10:24 by timtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

CFLAGS = -Wall -Wextra -Werror -IHeaders

OBJDIR = objs

VPATH = srcs

S_SRCS = server.c

C_SRCS = client.c

S_OBJS = $(addprefix $(OBJDIR)/, $(S_SRCS:.c=.o))

C_OBJS = $(addprefix $(OBJDIR)/, $(C_SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

all: build_libft $(NAME) $(NAME2)

build_libft:
	$(MAKE) -C libft

$(NAME): $(S_OBJS)
	cc $(CFLAGS) $(S_OBJS) libft/libft.a -o $(NAME)

$(NAME2): $(C_OBJS)
	cc $(CFLAGS) $(C_OBJS) libft/libft.a -o $(NAME2)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all

.PHONY: all build_libft clean fclean re
