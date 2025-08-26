# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 21:35:07 by timtan            #+#    #+#              #
#    Updated: 2025/08/26 17:15:29 by timtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -IHeaders

NAME = libftprintf.a
OBJ_DIR = objs
VPATH = srcs:srcs/tools:srcs/converts:srcs/bonus

SRC_FILES = ft_printf.c		fstring_parser.c	checks.c\
			ft_itoa.c		ft_printstr.c		ft_revstr.c\
			ft_strjoin.c	ft_strdup.c			ft_strlen.c\
			ft_uinttoa.c	c_convert.c			s_convert.c\
			p_convert.c		d_convert.c			u_convert.c\
			x_convert.c\

BSC_FILES = ft_printf_bonus.c	fstring_parser_bonus.c	checks_bonus.c\
			ft_itoa_bonus.c		ft_printstr_bonus.c		ft_revstr_bonus.c\
			ft_strjoin_bonus.c	ft_strdup_bonus.c		ft_strlen_bonus.c\
			ft_uinttoa_bonus.c	c_convert_bonus.c		s_convert_bonus.c\
			p_convert_bonus.c	d_convert_bonus.c		u_convert_bonus.c\
			x_convert_bonus.c\

OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
B_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(BSC_FILES:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

bonus: $(B_OBJ_FILES)
	ar rcs $(NAME) $(B_OBJ_FILES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
