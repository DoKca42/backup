SRCS = main.c atoi.c operations.c

NAME = do-op

OBJ = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = cc $(FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

$(NAME): $(SRCS) $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)