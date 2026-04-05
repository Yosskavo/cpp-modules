#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main()
{
	PresidentialPardonForm p("Hado");
	RobotomyRequestForm r("zar");
	ShrubberyCreationForm s("shadom");
	Bureaucrat b("3afak", 57);

	try
	{
		p.execute(b);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		r.execute(b);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		s.execute(b);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	b.executeForm(s);
	b.executeForm(r);
	b.executeForm(p);
}
