NAME = brain

SRC = WrongAnimal.cpp Animal.cpp WrongCat.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++ -Wall -Wextra -Werror -std=c++98

%.o : %.cpp WrongAnimal.hpp Animal.hpp WrongCat.hpp Cat.hpp Dog.hpp Brain.cpp
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
