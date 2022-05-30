NAME = so_long

SRCS = ./src/so_long.c ./src/sl_utils/keys_manager.c ./src/sl_utils/map_manager.c \
		./src/sl_utils/movements.c ./src/sl_utils/errors_handler.c \
		./src/sl_utils/game_utils.c


SRCS_BONUS = ./src_bonus/so_long.c ./src_bonus/sl_utils/keys_manager.c ./src_bonus/sl_utils/map_manager.c \
		./src_bonus/sl_utils/movements.c ./src_bonus/sl_utils/errors_handler.c \
		./src_bonus/sl_utils/game_utils.c ./src_bonus/sl_utils/animation.c 


GNL_SRCS = ./src/gnl/get_next_line_utils.c ./src/gnl/get_next_line.c

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = ./src/libft/libft.a

LIBFT = ./src_bonus/libft/libft.a


HEADER = ./src/so_long.h

HEADER_BONUS = ./src_bonus/so_long.h



CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME) $(HEADER) 



$(NAME):  $(SRCS) $(HEADER) $(OBJS)
	@gcc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS) $(GNL_SRCS) $(LIBFT)  -o $@
	@echo $@ ----------------- ready -----------------

bonus : $(SRCS_BONUS) $(OBJS_BONUS) $(HEADER_BONUS) $(LIBFT)
	@gcc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS_BONUS) $(GNL_SRCS) $(LIBFT)  -o so_long_bonus
	@echo $@ ----------------- ready -----------------


$(LIBFT):
	@make -C ./src/libft
	@make -C ./src_bonus/libft

clean:
	@make clean -C ./src/libft
	@make clean -C ./src_bonus/libft

fclean: clean
	rm -rf $(OBJS) $(NAME) $(OBJS_BONUS) so_long_bonus
	make fclean -C ./src/libft
	make fclean -C ./src_bonus/libft

re: fclean all

.PHONY: all re clean fclean
