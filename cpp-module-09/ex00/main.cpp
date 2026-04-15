// #include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Missing argument" << std::endl;
		return (1);
	}
	std::ifstream file(av[1]);

	if (file.fail())
	{
		std::cerr << "Faild to open the file" << std::endl;
		return (2);
	}
	
	return (0);
}
