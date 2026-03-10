#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat b("princess", 10);
	int i;

	i = 0;
	try
	{
		while (i < 150) {
			std::cout << b << std::endl;
			b.DecreamentGrade();
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "this : " << e.what() << std::endl;
	}
	try
	{
		while (i < 151) {
			std::cout << b << std::endl;
			b.IncreamentGrade();
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "this : " << e.what() << std::endl;
	}
}
