#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private :
		std::string type;
	public  :
		WrongCat(void);
		WrongCat(const WrongCat &cat);
		~WrongCat(void);
		WrongCat &operator=(const WrongCat &cat);
		void makeSound(void) const;
		std::string getType(void) const;
		void setType(const std::string & p_name);
};

#endif
