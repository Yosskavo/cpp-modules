NAME = tests

SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++ -Wall -Wextra -Werror -g -std=c++98

%.o : %.cpp Account.hpp
	$(CPP) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

clean : 
	@rm -rv $(OBJ)

fclean : clean
	@rm -rv $(NAME)

re : fclean all

.PHONY : clean re fclean all
