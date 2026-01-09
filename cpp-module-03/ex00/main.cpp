#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Hado");
	ClapTrap b("Raikodo");
	
	a.attack("Raiodo");
	for (int i = 0; i  < 10 ; i++)
	{
		b.beRepaired(10);
	}
	b.beRepaired(1);
	a.takeDamage(10);
	a.takeDamage(1);
}
