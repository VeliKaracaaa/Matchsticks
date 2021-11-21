##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## MakefileLib
##

SRC =	my_getnbr.c		\
		my_putchar.c	\
		my_strlen.c		\
		my_putstr.c		\
		my_put_nbr.c

OBJ =	$(SRC:.c=.o)

NAME = libmy.a

CFLAGS = -I ./../../include

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all