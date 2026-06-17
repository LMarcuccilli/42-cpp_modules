#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	// constructor
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);

	// operator
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

	// destructor
	~RobotomyRequestForm();

	// function
	void doExecute() const;
};

#endif
