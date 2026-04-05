#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("Uknown"), _grade(150)
{
}


Bureaucrat::Bureaucrat(const Bureaucrat &b) : _name(b._name), _grade(b._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & b)
{
	if (this == &b)
		return (*this);
	this->_grade = b._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string & name, const short grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

short Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string  Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::IncreamentGrade(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::DecreamentGrade(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade too low !!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade too high !!";
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & b)
{
	os << b.getName() + ", bureaucrat grade " << b.getGrade();
	return (os);
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << this->_name + " couldn’t sign " + f.getName() + " because " + e.what() << std::endl;
		return ;
	}
	std::cout << this->_name + " signed " + f.getName() << std::endl;
}

