#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	int as[5] = {1,2,3,4,5};

	sp.RangeOfIterators(as, 5);
	try
	{
		sp.addNumber(12);
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		sp.RangeOfIterators(as, 1231231);
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Span s(1);
		s.shortestSpan();
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
