#include "Span.hpp"
#include <iostream>
#include <stack>

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

	std::vector<int> as;

	for (int i = 0; i < 5; i++)
	{
		as.push_back(i);
	}
	sp.RangeOfIterators<std::vector<int> >(as.begin(), as.end(), 5);
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
		sp.RangeOfIterators<std::vector<int> >(as.begin(), as.end(), 123123);
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

	Span asd(10);
	std::deque<int> s;
	for (int i = 0; i < 5; i++)
	{
		s.push_back(i);
	}
	asd.RangeOfIterators< std::deque<int> >(s.begin(), s.end(), 5);
	std::cout << asd.shortestSpan() << std::endl;
	std::cout << asd.longestSpan() << std::endl;
	return 0;
}
