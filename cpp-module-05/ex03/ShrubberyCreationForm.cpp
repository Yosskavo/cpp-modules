#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", false, 145, 137) , _target(target)
{
}

void ShrubberyCreationForm::execute(const Bureaucrat & b) const
{
	if (b.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();

	std::ofstream file_target((this->_target + "_shrubbery").c_str());

	if (file_target.is_open())
	{
		file_target << "    ^" << std::endl;
		file_target << "   / \\" << std::endl;
		file_target << "  /   \\" << std::endl;
		file_target << " /_____\\" << std::endl;
		file_target << "   | |" << std::endl;
	}
	else {
		throw std::runtime_error("Faild to create file");
	}
	file_target.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & s)
{
	if (this == &s)
		return (*this);
	this->_target = s._target;
	return (*this);
}
