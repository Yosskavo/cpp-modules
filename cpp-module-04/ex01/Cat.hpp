#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private :
		std::string type;
		Brain *brain;
	public  :
		Cat(void);
		Cat(const Cat &cat);
		~Cat(void);
		Cat &operator=(const Cat &cat);
		std::string getType(void) const;
		void setType(const std::string &p_name);
		void makeSound(void) const;
};

#endif
