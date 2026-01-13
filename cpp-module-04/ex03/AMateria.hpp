#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public :
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria & other);
		virtual ~AMateria(void);
		AMateria &operator=(const AMateria & materia);
		void setType(const std::string &type);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
