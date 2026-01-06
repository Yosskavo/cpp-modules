#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie *obj;
	Zombie nn;
	
	randomChump("world");
	obj = newZombie("hello");
	nn.setName("hado");
	if (obj == NULL)
	{
		std::cout << "Faild allocatin" << std::endl;
		return (2);
	}
	obj->announce();
	delete obj;
}
