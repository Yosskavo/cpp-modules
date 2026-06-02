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
		std::cout << "Before : ";
		p.print_it("vector");
		std::cout << std::endl;
		p.SortVector();
		p.SortDeque();
		std::cout << "After : ";
		p.print_it("vector");
		std::cout << std::endl;

		p.print_time("vector");
		p.print_time("deque");
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
