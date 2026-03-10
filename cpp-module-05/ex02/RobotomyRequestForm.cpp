#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm("Robot", false, 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & r)
{
	if (this == &r)
		return (*this);
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat & b) const
{
	if (b.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();

	std::cout << "Higher Higher" << std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << this->_target + " has been robotomized successfull" << std::endl;
	}
	else {
		std::cout << this->_target + " robotomy failed" << std::endl;
	}
}

