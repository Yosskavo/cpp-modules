#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base * generate(void)
{
	static bool flag = false;
	if (!flag)
	{
		std::srand(static_cast<unsigned int>(std::time(0)));
		flag  = true;
	}

	int	x = std::rand() % 3;

	if (x == 0)
		return (new A);
	if (x == 1)
		return (new B);
	return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Uknown class type" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch(std::exception & e)
	{
	}

	try
	{
		B a = dynamic_cast<B&>(p);
		(void)a;
		std::cout << "B" << std::endl;
		return ;
	}
	catch(std::exception & e)
	{
	}

	try
	{
		C a = dynamic_cast<C&>(p);
		(void)a;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(std::exception & e)
	{
	}
	std::cout << "Uknown class type" << std::endl;
}
