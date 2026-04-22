#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Missing argument" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange a;

		a.calculate_value(av[1]);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
