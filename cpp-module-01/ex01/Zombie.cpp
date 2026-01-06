#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void)
{
	return (name);
}

void Zombie::setName(std::string str)
{
	name = str;
}

Zombie::~Zombie(void)
{
	std::cout << "The zombie " << name << " has been eliminated" << std::endl;
}
