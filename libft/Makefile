NAME = libft.a

SOURCES = $(wildcard ./*.c)
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
FLAGS ?= -c -Wall -Wextra -Werror
FLAGS += -I./

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $@ $^
	@ranlib $@

%.o: ./%.c
	@$(CC) $(FLAGS) $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
