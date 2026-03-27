#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	(void)ac;
	if (ac != 2)
	{
		std::cout << "Should inter a string to convert" << std::endl;
		return (1);
	}
	ScalarConverter::Converter(av[1]);
}
