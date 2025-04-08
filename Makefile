##
## EPITECH PROJECT, 2024
## My_New_Hunter
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)	\
		$(wildcard src/*.c) \
		$(wildcard lib/my/*.c)

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	my_world

CFLAGS	+=	-L./lib/my -I./include -g3  \
-lcsfml-graphics -lcsfml-system -lcsfml-window -lm -lcsfml-window

all:	$(NAME)

$(NAME)	:${OBJ}
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) vgcore.* $(OBJ) *.gch

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

.PHONY:	all	build	clean	fclean	re
