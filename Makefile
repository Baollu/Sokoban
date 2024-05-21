##
## EPITECH PROJECT, 2023
## test
## File description:
## test
##

SRC	=	main.c			\
		condition_wl.c		\
		generate_map.c		\
		control_left_right.c	\
		play.c			\
		control_player.c	\
		reset_map.c		\
		find_player.c		\
		rules.c			\
		map_verif.c		\

CFLAGS	=	-Wall -Wextra

FLAGS	=	 -L ./lib/my -lmy -I include -l ncurses

NAME	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	make clean -C lib/my
	rm -f $(OBJ) $(NAME)

fclean: clean

re: fclean all

.PHOMY: all clean fclean re
