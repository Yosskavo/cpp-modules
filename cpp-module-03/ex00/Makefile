NAME = ClapTrap

SRC = main.cpp ClapTrap.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++ -Wall -Wextra -Werror -std=c++98

%.o : %.cpp ClapTrap.hpp
	$(CPP) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean re fclean all
