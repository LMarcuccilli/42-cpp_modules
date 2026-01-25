#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form valid("valid form", 50, 50);
		Bureaucrat b("patrick", 70);
		
		std::cout << valid.getIsSigned() << std::endl;
		b.signForm(valid);
		std::cout << valid.getIsSigned() << std::endl;
		Form invalid("human right 2.0", 100, 155);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return 0;
}
