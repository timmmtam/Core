# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 18:30:48 by timtan            #+#    #+#              #
#    Updated: 2026/02/09 18:26:40 by timtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror -IHeaders

OBJDIR = objs

VPATH = srcs

SRCS =	main.c	draw.c	events.c	utils.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

all: build_libft $(NAME)

build_libft:
	$(MAKE) -C libft

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) -L/usr/X11/lib -lX11 -lXext -L./minilibx-linux -lmlx -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all build_libft clean fclean re
