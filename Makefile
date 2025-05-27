SRC = main.c\
	create_map.c\

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
