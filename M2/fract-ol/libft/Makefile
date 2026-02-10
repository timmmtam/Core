# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timtan <timtan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 13:27:40 by timtan            #+#    #+#              #
#    Updated: 2026/02/07 15:53:45 by timtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -IHeaders

NAME = libft.a

OBJDIR = objs

VPATH = srcs:srcs/libft/:srcs/get_next_line/:srcs/ft_printf/

#----------------------------LIBFT FILES---------------------------------------#
LFTSRC =	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c \
			ft_isascii.c	ft_isprint.c	ft_strlen.c \
			ft_memset.c		ft_bzero.c		ft_memcpy.c \
			ft_memmove.c	ft_strlcpy.c	ft_strlcat.c \
			ft_toupper.c	ft_tolower.c	ft_strchr.c \
			ft_strrchr.c	ft_strncmp.c	ft_memchr.c \
			ft_memcmp.c		ft_strnstr.c	ft_atoi.c \
			ft_calloc.c		ft_strdup.c		ft_substr.c \
			ft_strjoin.c	ft_strtrim.c	ft_split.c \
			ft_itoa.c		ft_strmapi.c	ft_striteri.c \
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c \
			ft_putnbr_fd.c	ft_lstnew.c		ft_lstadd_front.c \
			ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c \
			ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c \
			ft_lstmap.c		ft_atol.c		ft_atof.c

LFTOBJ = $(addprefix $(OBJDIR)/, $(LFTSRC:.c=.o))
#------------------------------------------------------------------------------#


#---------------------------------GNL FILES------------------------------------#
GNLSRC = get_next_line.c	get_next_line_utils.c

GNLOBJ = $(addprefix $(OBJDIR)/, $(GNLSRC:.c=.o))
#------------------------------------------------------------------------------#


#-----------------------------FT_PRINTF FILES----------------------------------#
PRINTFSRC = ft_printf.c		fstring_parser.c	checks.c\
			pf_itoa.c		pf_printstr.c		pf_revstr.c\
			pf_strjoin.c	pf_strdup.c			pf_strlen.c\
			pf_uinttoa.c	c_convert.c			s_convert.c\
			p_convert.c		d_convert.c			u_convert.c\
			x_convert.c

PRINTFOBJ = $(addprefix $(OBJDIR)/, $(PRINTFSRC:.c=.o))
#------------------------------------------------------------------------------#

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LFTOBJ) $(GNLOBJ) $(PRINTFOBJ)
	ar rcs $(NAME) $(LFTOBJ) $(GNLOBJ) $(PRINTFOBJ)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
