##
## EPITECH PROJECT, 2018
## Evalexpr
## File description:
## Makefile
##

SRC		=	main2.c		\
			fill_str.c		\
			str_to_word_array.c		\
			prompt.c		\
			path.c		\
			free.c		\
			cd.c		\
			execution.c		\
			status.c		\
			init.c		\
			env.c		\
			add_to_list.c		\
			env2.c		\
			minishell.c		\
			help_tab.c		\
			minishell2.c

OBJ		=	$(SRC:.c=.o)

NAME	=	mysh

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
