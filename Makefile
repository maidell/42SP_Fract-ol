NAME =      fractol
HEADER =    -I ./includes
SRC_DIR =   ./sources
OBJ_DIR =	./objects
LIBFT 	=	./libft/libft.a
SRC_FILES =   	main.c draw_fractal.c fractais.c \
				hook.c

CC = 		cc -Wall -Wextra -Werror 

CFLAGS =    -g3 -O3 -Imlx -Lmlx -lmlx -lXext -lX11 -lm

SRC =       $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ =       $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(CFLAGS)

$(LIBFT):
	make -C ./libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(HEADER) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
