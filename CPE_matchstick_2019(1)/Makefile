##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC = 	src/matchstick.c				\
		src/malloc_and_print_board.c	\
		src/game_gestion.c				\
		src/game_ia.c					\
		src/player.c

OBJ =	$(SRC:.c=.o)

NAME = matchstick

CFLAGS = -I./inlude -g3 -Wall -Wextra

all: $(NAME)

make_lib:
	make -C lib/my

$(NAME): make_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) -Llib/my -lmy -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all
