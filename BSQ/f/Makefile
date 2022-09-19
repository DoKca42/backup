NAME = bsq

SOURCES = main.c \
		  ft_functional.c \
		  is_file_valid.c \
		  map.c \
		  parsing.c \
		  find_square.c

OBJECTS = $(SOURCES:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc $(FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

$(NAME): $(SOURCES) $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -o $(NAME)
