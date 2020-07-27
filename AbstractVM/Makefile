##
## EPITECH PROJECT, 2020
## make
## File description:
## make
##

SRC =   $(wildcard src/*.cpp) \
		$(wildcard inc/Exception/*.cpp)

OBJ =   $(SRC:.cpp=.o)

NAME    =   abstractVM

$(NAME):    $(OBJ)
	g++ -I src/ -o $(NAME) $(OBJ)

all:    $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
