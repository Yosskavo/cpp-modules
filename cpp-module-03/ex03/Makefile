NAME = DiamondTrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp DiamondTrap.cpp FragTrap.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++ -Wall -Wextra -Werror -std=c++98

%.o : %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.cpp DiamondTrap.cpp
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
