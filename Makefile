SRC = main.c\
	print_error.c\
	init.c\
	parsers/texture_parser.c\
	parsers/matrix_parser.c\
	parsers/extension.c\
	parsers/parser.c\
	map_structure/create_map_file_array.c\
	map_structure/map_matrix.c\
	map_structure/texture_paths.c\
	free/free_array.c\
	free/free_all.c\
	utils/str_is_digit.c\
	utils/split_by_space.c\
	utils/ft_arraylen.c\
	utils/ft_printarray.c\
	mlx_display/close_win.c\
	mlx_display/handle.c\

CC = cc
OBJS = $(SRC:.c=.o)
NAME = cub3D
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C ./libft
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -L./libft -lft  $(MLXFLAGS)

clean:
	@make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re 
