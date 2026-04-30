#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, const char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error : not enough argument" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe p;

		p.InsertElements(av + 1);
		std::cout << "This : ";
		p.print_it();
		std::cout << std::endl;
		std::cout << "using vector's " << std::endl;
		p.SortVector();
		std::cout << "using deque's " << std::endl;
		p.SortDeque();
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
