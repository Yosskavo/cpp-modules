#include "Form.hpp"
#include <iostream>

Form::Form(void) : _name("Unknown"), _is_signed(false), _grade_sign(150), _grade_execute(150)
{
}

Form::Form(const Form &f) : _name(f._name), _is_signed(f._is_signed), _grade_sign(f._grade_sign), _grade_execute(f._grade_execute)
{
}

Form::Form(const std::string &name, const bool is_signed, const short grade_sign, const short grade_execute) : _name(name), _is_signed(is_signed), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	if (this->_grade_execute < 1 || this->_grade_sign < 1)
		throw GradeTooHighException();
	if (this->_grade_execute > 150 || this->_grade_sign > 150)
		throw GradeTooLowException();
}

Form & Form::operator=(const Form & f)
{
	if (this != &f)
	{
		this->_is_signed = f._is_signed;
	}
	return (*this);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

Form::~Form()
{
}

std::string	Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_is_signed;
}

short Form::getGradeSign() const
{
	return this->_grade_sign;
}

short Form::getGradeExecute() const
{
	return this->_grade_execute;
}

std::ostream & operator<<(std::ostream & os, const Form & f)
{
	os << "The name : " + f.getName() + " , sign status : ";
	if (f.getIsSigned())
		os << " Yes";
	else
		os << " No";
	os << " , grade sign : " << f.getGradeSign() << " , grade execute : " << f.getGradeExecute();
	return os;
}

void Form::beSigned(const Bureaucrat & b)
{
	if (b.getGrade() > this->_grade_sign)
	{
		throw GradeTooLowException();
	}
	this->_is_signed = true;
}

