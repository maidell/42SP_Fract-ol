NAME =      fractol
HEADER =    -I ./includes
SRC_DIR =   ./sources
OBJ_DIR =	./objects
LIBFT 	=	./libft/libft.a
SRC_FILES =    main.c draw_fractal.c fractais.c handle_error.c 

SRC =        $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ =        $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
CFLAGS =    -g3 -O3 -Imlx -Lmlx -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	cc $(HEADER) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re bonus