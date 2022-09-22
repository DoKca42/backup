SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

NAME = libft.a

OBJ = ${SRCS:.c=.o}

GCF = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

srcs/ft_putchar.o: srcs/ft_putchar.c
	gcc $(GCF) -c srcs/ft_putchar.c -o srcs/ft_putchar.o

srcs/ft_putstr.o: srcs/ft_putstr.c
	gcc $(GCF) -c srcs/ft_putstr.c -o srcs/ft_putstr.o

srcs/ft_strcmp.o: srcs/ft_strcmp.c
	gcc $(GCF) -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o

srcs/ft_strlen.o: srcs/ft_strlen.c
	gcc $(GCF) -c srcs/ft_strlen.c -o srcs/ft_strlen.o

srcs/ft_swap.o: srcs/ft_swap.c
	gcc $(GCF) -c srcs/ft_swap.c -o srcs/ft_swap.o
