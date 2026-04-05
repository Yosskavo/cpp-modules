#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

class Form;

class Bureaucrat
{
	private :
		const std::string	_name;
		short 				_grade;
	public :
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat & b);
		~Bureaucrat(void);
		Bureaucrat &operator= (const Bureaucrat & b);
		Bureaucrat(const std::string &name, const short grade);
		std::string		getName(void)	const;
		short			getGrade(void)	const;
		void			IncreamentGrade(void);
		void			DecreamentGrade(void);
		void 			signForm(Form &f);
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
