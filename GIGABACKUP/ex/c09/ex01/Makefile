SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

NAME = libft.a

OBJ = ${SRCS:.c=.o}

GCC = gcc -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) "srcs/"*.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

srcs/ft_putchar.o: srcs/ft_putchar.c
	GCC -c srcs/ft_putchar.c -o srcs/ft_putchar.o

srcs/ft_putstr.o: srcs/ft_putstr.c
	GCC -c srcs/ft_putstr.c -o srcs/ft_putstr.o

srcs/ft_strcmp.o: srcs/ft_strcmp.c
	GCC -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o

srcs/ft_strlen.o: srcs/ft_strlen.c
	GCC -c srcs/ft_strlen.c -o srcs/ft_strlen.o

srcs/ft_swap.o: srcs/ft_swap.c
	GCC -c srcs/ft_swap.c -o srcs/ft_swap.o
