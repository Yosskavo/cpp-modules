#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	protected :
		std::string ideas[100];
	public :
		Brain(void);
		Brain(const std::string (&p_name)[100]);
		Brain(const Brain &brain);
		~Brain(void);
		Brain &operator=(const Brain &brain);
};

#endif
