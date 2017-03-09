
CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INCL)

SRC = get_next_line.c

BIN = $(SRC:.c=.o)

INCL = ./libft

NAME = a.out

.PHONY: clean fclean re

$(NAME):
	$(CC) $(CFLAGS) ./libft/*.c $(SRC) 

all: $(NAME) 
	
clean:
	/bin/rm -f $(BIN)

fclean: clean
	/bin/rm -f $(NAME)	

re: fclean all

debug:
	$(CC) $(CFLAGS) ./libft/*.c -g $(SRC) 
