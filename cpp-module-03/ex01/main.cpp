#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("Hado");

	for (int i = 0; i < 49; i++)
	{
		a.attack("Dimo");
	}
	a.beRepaired(1);
	a.takeDamage(110);
	a.takeDamage(2);
	a.guardGate();
	a.beRepaired(1);
}
