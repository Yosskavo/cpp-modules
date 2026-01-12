#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class WrongAnimal
{
	protected :
		std::string type;
	public :
		WrongAnimal(void);
		WrongAnimal(const std::string &p_name);
		WrongAnimal(const WrongAnimal &animl);
		WrongAnimal &operator=(const WrongAnimal &animal);
		virtual ~WrongAnimal(void);
		std::string getType(void);
		void setType(const std::string &p_name);
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif
