#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie *obj;
	
	obj = zombieHorde(10, "hadoo");
	if (obj == NULL)
	{
		std::cout << "Faild allocatin" << std::endl;
		return (2);
	}
	for (int i = 0; i < 10; i++)
	{
		obj[i].announce();
	}
	delete[] obj;
}
