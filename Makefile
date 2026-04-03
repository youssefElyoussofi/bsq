CC=cc
CFLAGS= -g
SRC= $(wildcard *.c)
OBJ=$(SRC:.c=.o)
NAME=bsq

$(NAME):$(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re