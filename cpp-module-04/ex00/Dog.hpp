#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private :
		std::string type;
	public  :
		Dog(void);
		Dog(const Dog &dog);
		~Dog(void);
		Dog &operator=(const Dog &dog);
		void makeSound(void) const;
		void setType(const std::string & p_name);
		std::string getType(void) const;
};

#endif
