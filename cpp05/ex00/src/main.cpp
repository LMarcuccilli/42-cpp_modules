#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Patrick", 10);
		std::cout << b << std::endl;

		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;

		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;

		// Trigger exception
		Bureaucrat c("TooHigh", 0); // throws GradeTooHighException

		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
