# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 13:27:40 by timtan            #+#    #+#              #
#    Updated: 2025/06/06 22:07:45 by timtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC_FILES = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \

BONUS_FILES = ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

B_OBJ_FILES = $(BONUS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) libft.h
	ar rcs $(NAME) $(OBJ_FILES)
#	cc $(CFLAGS) $(OBJ_FILES) -o $(PROGRAM_NAME)

bonus: $(B_OBJ_FILES) $(OBJ_FILES) libft.h
	ar rcs $(NAME) $(B_OBJ_FILES) $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES) $(B_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean clean re
