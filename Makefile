CC=gcc
flags=-Wall -Werror -Wextra
files=./src/*.c ./libft/libft.a
target=fdf

.PHONY: all clean fclean re libft

OS = $(shell uname)

all: libft
ifeq ($(OS),Darwin)
	$(CC) -o $(target) $(files) -lmlx -framework OpenGL -framework AppKit
else
	$(MAKE) -C ./minilibx
	$(CC) -o $(target) $(files) ./minilibx/libmlx.a -lmlx -lXext -lX11 -L ./minilibx -I ./minilibx -lm
endif
libft:
	$(MAKE) -C ./libft/ all
clean:
	rm -f ./src/*~
	rm -f ./src/*#
	rm -f *.o
	rm -f ./libft/*.o
	rm -f ./src/*.o
fclean: clean
	rm -f libft.a
	rm -f $(target)
re: fclean all
