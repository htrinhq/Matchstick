##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## desc
##

SRC	=	source/main.c	\
		source/my_atoi.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-W -Wall -Wextra -I include

##LDFLAGS	=	-L ./lib/ -lgnl

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	fclean clean all re
