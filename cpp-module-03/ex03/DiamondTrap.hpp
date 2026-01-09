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
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &diamond);
		DiamondTrap &operator=(const DiamondTrap & diamond);
		~DiamondTrap(void);
		void attack(const std::string &target);
		void whoAmI(void);
};

#endif
