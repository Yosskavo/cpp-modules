#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

class AForm;

class Bureaucrat
{
	private :
		const std::string	_name;
		short 				_grade;
	public :
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator= (const Bureaucrat & b);
		Bureaucrat(const std::string &name, const short grade);
		std::string		getName(void)	const;
		short			getGrade(void)	const;
		void			IncreamentGrade(void);
		void			DecreamentGrade(void);
		void 			signForm(AForm &f);
		void			executeForm(AForm const & form) const;
		class GradeTooHighException : public std::exception
		{
			virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char * what() const throw();
		};
};

std::ostream & operator<<(std::ostream &os, const Bureaucrat &b);

#endif
