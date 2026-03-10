#ifndef SHURUBBERYCREATIONFORM_HPP
# define SHURUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string			_target;
	public :
		ShrubberyCreationForm(const std::string & target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm & s);
		void execute(Bureaucrat const & executor) const;
};

#endif
