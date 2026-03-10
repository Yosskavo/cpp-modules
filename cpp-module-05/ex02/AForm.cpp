#include "AForm.hpp"
#include <iostream>

AForm::AForm(void) : _name("Unknown"), _is_signed(false), _grade_sign(150), _grade_execute(150)
{
}

AForm::AForm(const std::string &name, const bool is_signed, const short grade_sign, const short grade_execute) : _name(name), _is_signed(is_signed), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	if (this->_grade_execute < 1 || this->_grade_sign < 1)
		throw GradeTooHighException();
	if (this->_grade_execute > 150 || this->_grade_sign > 150)
		throw GradeTooLowException();
}

AForm & AForm::operator=(const AForm & f)
{
	if (this != &f)
	{
		this->_is_signed = f._is_signed;
	}
	return (*this);
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

AForm::~AForm()
{
}

std::string	AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_is_signed;
}

short AForm::getGradeSign() const
{
	return this->_grade_sign;
}

short AForm::getGradeExecute() const
{
	return this->_grade_execute;
}

std::ostream & operator<<(std::ostream & os, const AForm & f)
{
	os << "The name : " + f.getName() + " , sign status : ";
	if (f.getIsSigned())
		os << " Yes";
	else
		os << " No";
	os << " , grade sign : " << f.getGradeSign() << " , grade execute : " << f.getGradeExecute();
	return os;
}

void AForm::beSigned(const Bureaucrat & b)
{
	if (b.getGrade() > this->_grade_sign)
	{
		throw GradeTooLowException();
	}
	this->_is_signed = true;
}

