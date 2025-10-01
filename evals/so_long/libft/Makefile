.PHONY := all clean fclean re

NAME := libft.a

SRCS := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
ft_lstadd_at.c ft_lstnode_at.c ft_lstdelone_at.c ft_lstdup.c \
ft_dlstnew.c ft_dlstadd_front.c ft_dlstadd_back.c ft_dlstsize.c ft_dlstlast.c ft_dlstdelone.c \
ft_dlstclear.c ft_dlstadd_at.c ft_dlstnode_at.c ft_writeresult.c \
ft_printf/ft_printf.c ft_printf/printer_digit.c ft_printf/printer_string.c get_next_line.c

SRCS_UNOFF := ft_charcount.c ft_strcount.c ft_strreplace.c ft_convert_base.c ft_numlen.c \
ft_strtoupper.c ft_strtolower.c ft_strcmp.c ft_strstr.c ft_math_min_max.c ft_putcharrepeat.c \
ft_abs.c ft_freestrarray.c ft_strelement.c ft_strarray_join.c ft_strisnum.c ft_strstartswith.c \
ft_strendswith.c ft_strarray_size.c ft_strarrdup.c

FT_PRINTF := 

GET_NEXT_LINE := 

CFLAGS := -Werror -Wextra -Wall -I.

OBJS := $(SRCS:.c=.o)

OBJSUNOFF := $(SRCS_UNOFF:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJSUNOFF)
	@echo [$(NAME)] Compiling $(NAME) with `echo $(OBJS) $(OBJSUNOFF) | wc -w` object files...
	@ar rcs $@ $^
	@echo [$(NAME)] Compile complete.

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJSUNOFF)
	@echo [$(NAME)] Object files deleted.

fclean: clean
	@rm -f $(NAME)
	@echo [$(NAME)] Deleted.

re: fclean all
