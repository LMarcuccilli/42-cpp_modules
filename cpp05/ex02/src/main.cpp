#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(0));

	std::cout << "\n========== BAD CONSTRUCTOR TESTS ==========\n\n";
	try
	{
		Bureaucrat badB("BadBureaucrat", 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== BASIC TESTS ==========\n\n";

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat intern("Intern", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << boss << std::endl;
	std::cout << mid << std::endl;
	std::cout << intern << std::endl;

	std::cout << "\n========== SIGNING TESTS ==========\n\n";

	intern.signForm(shrub);     // should fail
	mid.signForm(shrub);        // should succeed

	intern.signForm(robot);     // should fail
	mid.signForm(robot);        // should succeed

	intern.signForm(pardon);    // should fail
	boss.signForm(pardon);      // should succeed

	std::cout << "\n========== EXECUTION TESTS ==========\n\n";

	intern.executeForm(shrub);  // should fail (grade too low)
	mid.executeForm(shrub);     // should succeed

	intern.executeForm(robot); // should fail
	mid.executeForm(robot);    // should fail (exec grade too low)
	boss.executeForm(robot);   // should succeed (50% chance)

	intern.executeForm(pardon);// should fail
	mid.executeForm(pardon);   // should fail
	boss.executeForm(pardon);  // should succeed

	std::cout << "\n========== UNSIGNED FORM TEST ==========\n\n";

	ShrubberyCreationForm unsignedForm("garden");
	boss.executeForm(unsignedForm); // should throw: not signed

	std::cout << "\n========== DONE ==========\n";
	return 0;
}
