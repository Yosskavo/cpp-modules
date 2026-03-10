#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string		_name;
		bool			_is_signed;
		const short		_grade_sign;
		const short		_grade_execute;
	public :
		Form(void);
		Form(const std::string &name, const bool is_signed, const short grade_sign, const short grade_execute);
		~Form(void);
		Form & operator=(const Form & f);
		std::string getName() const;
		bool getIsSigned() const;
		short getGradeSign() const;
		short getGradeExecute() const;
		void beSigned(const Bureaucrat & b);
		class GradeTooHighException : public std::exception
		{
			virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char * what() const throw();
		};
};

std::ostream & operator<<(std::ostream &os, const Form & f);

#endif
