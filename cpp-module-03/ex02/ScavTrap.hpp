#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(const std::string &p_name);
		ScavTrap(const ScavTrap & scav);
		ScavTrap &operator=(const ScavTrap & scav);
		~ScavTrap(void);
		void guardGate(void);
		void attack(const std::string &name);
};

#endif
