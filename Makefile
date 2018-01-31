##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## desc
##

SRC	=	source/main.c	\
		source/my_atoi.c	\
		source/my_strlen.c	\
		source/map.c	\
		source/copycat.c	\
		source/game_loop.c	\
		source/user.c	\
		source/check_map.c	\
		source/errors.c	\
		source/ia.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-W -Wall -Wextra -I include -g

LDFLAGS	=	-L ./lib/print -lprint

all:	libmake $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

libmake:
	make -C ./lib/print

clean:
	rm -f $(OBJ)
	make clean -C ./lib/print

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/print

re:	fclean all

.PHONY:	fclean clean all re libmake
