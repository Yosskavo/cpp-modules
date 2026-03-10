#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public :
		AForm	*makeForm(const std::string &name_of_form, const std::string &name_of_target);
};

#endif
