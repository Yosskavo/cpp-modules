#include "Weapon.hpp"

void Weapon::setType(std::string str)
{
	type = str;
}

std::string Weapon::getType(void)
{
	return (type);
}

Weapon::Weapon(std::string str)
{
	type = str;
}
