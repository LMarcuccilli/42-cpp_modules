#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	// constructor
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);

	// operator
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

	// destructor
	~ShrubberyCreationForm();

	// function
	void doExecute() const;
};
