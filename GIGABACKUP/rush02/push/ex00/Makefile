CC = cc

CUR_DIR = $(shell pwd)

EXEC = rush-02

SRC = $(wildcard srcs/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror

HEADERS = $(CUR_DIR)/includes

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)

debug: $(OBJ)
	$(CC) -g -o $(EXEC) $(OBJ)
%.o : %.c
	$(CC) -c -I$(HEADERS) $< -o $@

clean:
	find . -name '*.o' -delete

fclean: clean
	rm -rf rush-02

re: fclean $(EXEC)
