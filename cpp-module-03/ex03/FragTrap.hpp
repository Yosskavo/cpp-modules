#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(const FragTrap & frag);
		FragTrap(const std::string &name);
		~FragTrap(void);
		FragTrap &operator=(const FragTrap &frag);
		void highFivesGuys(void);
};

#endif
