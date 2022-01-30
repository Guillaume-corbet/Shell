##
## EPITECH PROJECT, 2018
## Day11
## File description:
## task01
##

SRC	=	my_putchar.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_strcpy.c		\
		my_strlen.c		\
		convert.c		\
		display_number.c		\
		my_printf.c		\
		option1.c		\
		option2.c		\
		option3.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_printf.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
		@ar rc $(NAME) *.o

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

auteur:
	echo $(USER) > auteur
