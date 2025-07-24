# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 21:35:07 by timtan            #+#    #+#              #
#    Updated: 2025/07/24 19:34:01 by timtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = libftprintf.a
NAME = program

CFLAGS = -Wall -Wextra -Werror -I.

VPATH = convert tools

SRC_FILES = ft_printf.c\
			fstring_parser.c\
			c_convert.c\
			s_convert.c\
			p_convert.c\
			d_convert.c\
			u_convert.c\
			x_convert.c\
			flags.c\
			ft_itoa.c\
			ft_printstr.c\
			ft_revstr.c\
			ft_strjoin.c\
			ft_strlen.c\
			ft_uinttoa.c\
			main.c\

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(OBJ_FILES)
	cc $(CFLAGS) $(OBJ_FILES) -o $(NAME)

#$(NAME): $(OBJ_FILES)
#	ar rcs $(NAME) $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
