SO_LONG = so_long

SRCS = ./src/so_long.c ./src/sl_utils/keys_manager.c ./src/sl_utils/map_manager.c

GNL_SRCS = ./src/gnl/get_next_line_utils.c ./src/gnl/get_next_line.c

OBJS	= $(SRCS:.c=.o)

LIBFT = ./src/libft/libft.a

HEADER = ./src/so_long.h


CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(SO_LONG) $(HEADER)

$(SO_LONG):  $(SRCS) $(HEADER)
	@gcc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS) $(GNL_SRCS) $(LIBFT)  -o $@
	@echo $@ ----------------- ready -----------------


$(LIBFT):
	@make -C ./src/libft

clean:
	@make clean -C ./src/libft

fclean: clean
	rm -rf $(OBJS)
	make fclean -C ./src/libft

re: fclean all

.PHONY: all re clean fclean