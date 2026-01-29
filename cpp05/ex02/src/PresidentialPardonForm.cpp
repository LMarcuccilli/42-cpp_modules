#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
	: AForm(other), _target(other._target)
{
}

// Operator
PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Function
void PresidentialPardonForm::doExecute() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox";
}
