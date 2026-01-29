#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	// constructor
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(PresidentialPardonForm const &other);

	// operator
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

	// destructor
	~PresidentialPardonForm();

	// function
	void doExecute() const;
};
