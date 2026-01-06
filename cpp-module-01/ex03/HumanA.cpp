#include "HumanA.hpp"
#include <iostream>

void	HumanA::attack(void)
{
	std::cout << name << " attack with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(Weapon &type) : weapon(type)
{
}

HumanA::HumanA(std::string str, Weapon &type) : name(str), weapon(type)
{
}
