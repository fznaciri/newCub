  
C = gcc -I /usr/local/include
MLX = -L mlx_lib -lmlx 
DEP = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
NAME = cub3D
D = -g
SRC = ./src/*.c ./src/utils/*.c ./src/parser/*.c

all: $(NAME)

$(NAME):
	./compile.sh 2 LCF main.c $(C) -g -o $(NAME) $(SRC) $(DEP) -include malloc.h -fsanitize=address
	# @$(C) $(FLAGS) -o $(NAME) $(SRC) $(DEP)
debug:
	@$(C) $(FLAGS) -o $(NAME) $(SRC) $(DEP) $(D) -fsanitize=address
	#@lldb $(NAME)
run:
	@./$(NAME)

clean:
	@rm -rf $(NAME)
re: clean all