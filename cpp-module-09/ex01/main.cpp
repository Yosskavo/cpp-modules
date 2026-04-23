#include "RPN.hpp"
#include <iostream>
#include <exception>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalide number of argument" << std::endl;
	}
	try {
		RPN a;

		std::cout << a.calculat_RPN(av[1]) << std::endl;
	} catch (const std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
}
