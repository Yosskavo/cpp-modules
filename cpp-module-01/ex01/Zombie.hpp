#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private :
		std::string name;

	public :
		void announce(void);
		std::string getName(void);
		void setName(std::string name);
		~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
