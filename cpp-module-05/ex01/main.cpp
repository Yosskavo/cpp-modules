#include "Bureaucrat.hpp"
#include "Form.hpp"
// #include <iostream>

int main(void)
{
	Bureaucrat 		b1("Void", 10);
	Bureaucrat 		b2("Ragnarok", 5);
	Form			f("The luck", false, 8, 10);
	

	b1.signForm(f);
	b2.signForm(f);



	// int i;

	// i = 0;
	// try
	// {
	// 	while (i < 150) {
	// 		std::cout << b << std::endl;
	// 		b.DecreamentGrade();
	// 	}
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cout << "this : " << e.what() << std::endl;
	// }
	// try
	// {
	// 	while (i < 151) {
	// 		std::cout << b << std::endl;
	// 		b.IncreamentGrade();
	// 	}
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cout << "this : " << e.what() << std::endl;
	// }
}
