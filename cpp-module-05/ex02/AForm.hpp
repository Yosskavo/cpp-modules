#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{
	private :
		const std::string		_name;
		bool			_is_signed;
		const short		_grade_sign;
		const short		_grade_execute;
	public :
		AForm(void);
		AForm(const std::string &name, const bool is_signed, const short grade_sign, const short grade_execute);
		virtual ~AForm(void);
		AForm & operator=(const AForm & f);
		std::string getName() const;
		bool getIsSigned() const;
		short getGradeSign() const;
		short getGradeExecute() const;
		void beSigned(const Bureaucrat & b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char * what() const throw();
		};
};

std::ostream & operator<<(std::ostream &os, const AForm & f);

#endif
