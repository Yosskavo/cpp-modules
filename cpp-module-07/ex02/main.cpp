#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> a(10);
	Array<int> b;
	Array<int> d;
	Array<int> c(10);

	a[1] = 12312312;

	b = a;
	std::cout << b[1] << std::endl;
	c = a;
	std::cout << c[1] << std::endl;
	a = d;
	b = d;

	Array<int> l = a;
	try
	{
		std::cout << a[100];
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
