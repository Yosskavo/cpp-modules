#include "HumanB.hpp"
#include <iostream>

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attack with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &type)
{
	weapon = &type;
}

HumanB::HumanB(std::string str) : name(""), weapon(NULL)
{
	name = str;
}
