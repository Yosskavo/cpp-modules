#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private :
		std::string name;
	public :
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &diamond);
		DiamondTrap &operator=(const DiamondTrap & diamond);
		~DiamondTrap(void);
};

#endif
