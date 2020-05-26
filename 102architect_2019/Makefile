##
## EPITECH PROJECT, 2019
## 102architect
## File description:
## makefile
##

NAME	=	102architect

SRC	=	src/102architect.c		\
		src/error_handling.c		\
		src/help_display.c		\
		src/coord_and_matrix.c		\
		src/display.c			\
		src/my_strlen.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS=	-I./include/

CFLAGS	=	-W -Wextra -Wall -g3

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS) -lm

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
