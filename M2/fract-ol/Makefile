# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 18:30:48 by timtan            #+#    #+#              #
#    Updated: 2026/02/12 14:28:21 by timtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror -IHeaders

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

OBJDIR = objs

VPATH = srcs

SRCS =	main.c	draw.c	events.c	utils.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) -lX11 -lXext -L./minilibx-linux -lmlx -lm

$(MLX):
	make -C minilibx-linux

$(LIBFT):
	make -C libft

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJDIR)
	rm -rf minilibx-linux/obj

fclean: clean
	@$(MAKE) -C minilibx-linux clean
	@$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all build_libft clean fclean re
