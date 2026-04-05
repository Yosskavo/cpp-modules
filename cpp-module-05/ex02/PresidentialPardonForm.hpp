#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string		_target;
	public :
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string & target);
		PresidentialPardonForm(const PresidentialPardonForm & p);
		~PresidentialPardonForm(void);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & p);
		void execute(Bureaucrat const & b) const;
};

#endif
