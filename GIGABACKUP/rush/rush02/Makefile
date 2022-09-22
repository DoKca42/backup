CC = gcc

CUR_DIR = $(shell pwd)

EXEC = rush-02

SRC = $(CUR_DIR)/srcs/*.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror

HEADERS = $(CUR_DIR)/includes

$(EXEC): $(OBJ)
	$(CC) -o $@ $<

%.o : %.c
	clear && gcc -Wall -Wextra -Werror -c -I$(HEADERS) $< -o $@

clean:
	find . -name '*.o' -delete

fclean: clean
	rm -rf rush-02
