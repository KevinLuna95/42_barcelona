NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror 
MLXFLAGS = -framework OpenGL -framework AppKit -lm

SOURCES = main.c initializing.c moves.c check_map.c check_map_healpers.c healpers.c
SOURCES_PATH = ./src
MLX_PATH = ./mlx
OBJS_PATH = ./build
LIBFT_PATH = ./libft
MLX = $(MLX_PATH)/libmlx.a
LIBFT = $(LIBFT_PATH)/libft.a
HEADER = $(SOURCES_PATH)/game.h

all: makes $(NAME) 

makes:
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)

OBJS = $(addprefix $(OBJS_PATH)/, ${SOURCES:.c=.o})

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(MLXFLAGS)

$(MLX):
	make -C $(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJS_PATH)/%.o: 	$(SOURCES_PATH)/%.c $(HEADER) Makefile
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJS_PATH)

fclean: clean
	make clean -C $(MLX_PATH)
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all