##
## EPITECH PROJECT, 2018
## Evalexpr
## File description:
## Makefile
##

SRC		=	src/*.c

OBJ		=	$(SRC:.c=.o)

NAME	=	42sh

all:	clean fclean $(NAME)

$(NAME):
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -Llib/my/. -lmy -Llib/my_printf/. -lmy_printf

valgrind:
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -Llib/my/. -lmy -Llib/my_printf/. -lmy_printf -g3

warning:
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -Llib/my/. -lmy -Llib/my_printf/. -lmy_printf -Wall -Werror

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:
		fclean all

auteur:
		echo $(USER) > auteur
