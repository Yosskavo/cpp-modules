#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
class Test : public Base{};
int main()
{
	{
		std::cout << "first test : " << std::endl;
		for (int i = 0; i < 10; i++)
		{
			Base * test = generate();
			std::cout << "the " << i + 1 << " random resault : " ;
			identify(test);
			delete test;
		}
		Base * t = new Test;
		identify(t);
		delete t;
	}
	{
		std::cout << "second test : " << std::endl;
		A a;
		B b;
		C c;
		identify(a);
		identify(b);
		identify(c);

		Test t;
		identify(t);
	}
}
