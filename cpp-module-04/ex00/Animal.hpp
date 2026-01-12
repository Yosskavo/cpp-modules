#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class Animal
{
	protected :
		std::string type;
	public :
		Animal(void);
		Animal(const std::string &p_name);
		Animal(const Animal &animl);
		Animal &operator=(const Animal &animal);
		virtual ~Animal(void);
		virtual std::string getType(void) const;
		virtual void setType(const std::string &p_name);
		virtual void makeSound(void) const;
};

#endif
