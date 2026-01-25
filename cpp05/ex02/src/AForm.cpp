#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Helper function
void AForm::checkGrade(const int grade, const int minGrade) const
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > minGrade)
		throw AForm::GradeTooLowException();
}

// Constructor
AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const AForm &other) : _name(other.getName()),
								_isSigned(false),
								_signGrade(other.getSignGrade()),
								_execGrade(other.getExecGrade())
{
}

AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name),
																   _isSigned(false),
																   _signGrade(signGrade),
																   _execGrade(execGrade)
{
	checkGrade(_signGrade, 150);
	checkGrade(_execGrade, 150);
}

// Destructor
AForm::~AForm()
{
}

// Operator
AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	return *this;
}

// Getter
const std::string AForm::getName() const
{
	return _name;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

// Functions
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else
		_isSigned = true;
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low";
}

const char *AForm::NotsignedException::what() const throw()
{
	return "Form must be signed to execute";
}
