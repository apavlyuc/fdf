CC=gcc
flags=-Wall -Werror -Wextra
files=./src/*.c ./libft/libft.a
target=fdf

.PHONY: all clean fclean re libft

all: libft
	$(CC) -o $(target) $(files) -lmlx -framework OpenGL -framework AppKit
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
