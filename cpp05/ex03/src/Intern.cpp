#include "Intern.hpp"
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// Helper function
static AForm *makePresidentForm(const std::string target)
{
	return new PresidentialPardonForm(target);
}

static AForm *makeRobotomyForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm *makeShrubberyForm(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

// Function
AForm *Intern::makeForm(const std::string form, const std::string target)
{
	AForm *(*formFunc[])(const std::string target) = {
		&makePresidentForm,
		&makeRobotomyForm,
		&makeShrubberyForm
	};

	std::string formName[] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};

	for (int i = 0; i < 3; i++)
	{
		if (form == formName[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return formFunc[i](target);
		}
	}
	std::cout << "Intern couldn't create Form called " << form << std::endl;
	return NULL;
}
