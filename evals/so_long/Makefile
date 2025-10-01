.PHONY: all clean clean_all fclean fclean_all re re_all

NAME := so_long

LIBMLX := minilibx/libmlx_Linux.a

LIBFT := libft/libft.a

SRCS := so_long.c so_long_util.c mlx_util.c map_parser.c map_parser_2.c texture_parser.c hooks.c

OBJS := $(SRCS:.c=.o)

COMPILER := cc -Werror -Wextra -Wall -I. -Ilibft -Iminilibx -O3

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	@$(COMPILER) $(OBJS) $(LIBFT) $(LIBMLX) -lXext -lX11 -o $@
	@echo "[so_long] Compiled!"

%.o: %.c
	@$(COMPILER) $< -c -o $@

$(LIBFT):
	@make -C libft

$(LIBMLX):
	@make -C minilibx

clean:
	@rm -rf $(OBJS)
	@echo "[$(NAME)] Object files removed!"

clean_all: clean
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@echo "[$(NAME)] Removed!"

fclean_all: fclean
	@make -C libft fclean
	@make -C minilibx clean

re: fclean all

re_all: fclean_all all
