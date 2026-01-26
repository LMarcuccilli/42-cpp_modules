#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	RobotomyRequestForm form("Didier");
	Bureaucrat b("Patrick", 100);

	b.signForm(form);
	b.executeForm(form);
	return 0;
}
