##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC	=	my_putchar.c		\
		my_putstr.c		\
		my_strdup.c		\
		mini_printf.c		\
		my_put_nbr.c		\
		my_strcpy.c		\
		my_strlen.c		\
		my_getnbr.c		\

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	ar cr libmy.a $(OBJ)
	cp libmy.a ../

clean:
	rm -f $(OBJ)
	rm -f libmy.a ../libmy.a

fclean: clean

re: all fclean

.PHONY: all clean fclean re
