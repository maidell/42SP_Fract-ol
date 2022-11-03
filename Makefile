NAME =        fractol
HEADER =    -I ./includes
SRC_DIR =    ./sources
OBJ_DIR =    ./objects

SRC_FILES =    main.c

SRC =        $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ =        $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
CFLAGS =    -g3 -O3 -Imlx -Lmlx -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	cc $(HEADER) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus