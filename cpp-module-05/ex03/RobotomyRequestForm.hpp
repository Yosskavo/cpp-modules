#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string		_target;
	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm & r);
		RobotomyRequestForm(const std::string & s);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & r);
		void execute(Bureaucrat const & b) const;
};

#endif
