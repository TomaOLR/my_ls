##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Thomas Olry's Makefile made the 12/30/2019
##

SRC	=	srcs/main.c			\
		srcs/right.c			\
		srcs/ls_l.c			\
		srcs/ls_d.c			\
		srcs/ls_t.c			\
		srcs/ls_r.c			\
		srcs/directory.c		\
		srcs/recursive.c		\
		srcs/parsing.c			\

CC	=	gcc -o

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror  -I./include/ -L./lib/my -lmy

NAME	=	my_ls

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	$(CC) $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\e[44;1m----------------THATS WORK !!!----------------\e[0m"

clean:
	make clean -C lib/my
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C lib/my
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
