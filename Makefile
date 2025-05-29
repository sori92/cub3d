SRC = main.c\
	print_error.c\
	init.c\
	map_structure/create_map_file_array.c\
	map_structure/map_matrix.c\
	map_structure/texture_paths.c\
	free/free_array.c\
	free/free_all.c\
	utils/split_by_space.c\
	utils/ft_arraylen.c\
	utils/ft_printarray.c\

CC = cc
OBJS = $(SRC:.c=.o)
NAME = cub3D
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C ./libft
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -L./libft -lft

clean:
	@make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re 
