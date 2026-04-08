#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> i(10,1);

	i.push_back(9);
	try
	{
		std::cout << *easyfind(i, 1) << std::endl;
		std::cout << *easyfind(i, 9) << std::endl;
		easyfind(i, 5);

	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
