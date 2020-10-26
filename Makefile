  
C = gcc -I /usr/local/include
MLX = -L mlx_lib -lmlx 
DEP = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
NAME = cub3d
D = -g
SRC = ./src/*.c main.c

all: $(NAME)

$(NAME):
	@$(C) $(FLAGS) -o $(NAME) $(SRC) $(DEP)
debug:
	@$(C) $(FLAGS) -o $(NAME) $(SRC) $(DEP) $(D) -fsanitize=address
	#@lldb $(NAME)
run:
	@./$(NAME)

clean:
	@rm -rf $(NAME)
re: clean all