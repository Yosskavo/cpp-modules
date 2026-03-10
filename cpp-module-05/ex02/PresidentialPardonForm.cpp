#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm("president", false, 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & p)
{
	if (this == &p)
		return (*this);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & b) const 
{
	if (b.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();

	std::cout << this->_target + " has been pardoned by Zaphod Beeblebrox.";
}

