#include "Intern.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

AForm * Intern::makeForm(const std::string & name_of_form, const std::string & target_name)
{
	int	i;
	std::string table[] = 
	{
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};

	i = 0;
	while (i < 3)
	{
		if (name_of_form == table[i])
			break ;
		i++;
	}
	switch (i) {
		case (0) :
			std::cout << "Intern creates " +target_name << std::endl;
			return (new RobotomyRequestForm(target_name));
		case (1) :
			std::cout << "Intern creates " +target_name << std::endl;
			return (new ShrubberyCreationForm(target_name));
		case (2) :
			std::cout << "Intern creates " +target_name << std::endl;
			return (new PresidentialPardonForm(target_name));
		case (3) :
			std::cout << "Intern faild to create " +target_name+ " cause " +name_of_form+ " doesn't found" << std::endl;
			return (NULL);
	}
	return (NULL);
}
