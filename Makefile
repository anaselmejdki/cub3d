# Colors:
RED = \033[0;31m
YELLOW = \033[0;33m
BLACK = \033[0m
MAGENTA = \033[1;35m
CYAN = \033[36m
GREEN0 = \033[32m
GREEN1 = \033[38;5;121m
HIGHLIGHTER = \033[0;43m
# Files:

SRC =	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./parsing/parsing.c ./parsing/utils_2.c ./parsing/validation.c \
		./parsing/mapping.c ./parsing/checking.c  ./parsing/ft_texture.c \
		main.c

OBJ = $(SRC:.c=.o)

# Flags:
CC = cc
CFLAGS = -Wall -Wextra -Werror 
#LFLAGS = -L ./mlx -lmlx -lXext -lX11 -lm -lz
INCLUDES = mlx/libmlx.a

# Library:
NAME = cub3D
LIBFT = libft.a

# Targets:
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(CYAN)Making Cub3D..👾$(BLACK)"
	@$(CC) $(OBJ) $(LIBFT) $(CFLAGS)  -o $(NAME) $(LFLAGS)

$(LIBFT):
	@make -s -C libft
	@mv libft/libft.a .

clean:
	@echo "$(GREEN0)Cleaning 🧹$(BLACK)"
	@rm -rf $(OBJ)
	@make -s -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)Done cleaning ✨$(BLACK)"
	@rm -rf $(LIBFT)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re