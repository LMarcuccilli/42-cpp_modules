#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other), _target(other._target)
{
}

// Operator
ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Function
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw NotsignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "   ###\n"
			"  #o###\n"
			" #####o###\n"
			"#o#\\#|#/###\n"
			" ###\\|/#o#\n"
			"  # }|{  #\n"
			"    }|{\n";
}
