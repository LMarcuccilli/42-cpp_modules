#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdlib.h>

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other), _target(other._target)
{
}

// Operator
RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Function
void RobotomyRequestForm::doExecute() const
{
	std::cout << "DRRRRRRRRRR...";

	srand(time(0));
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " has not been robotomized, it failed" << std::endl;
}
