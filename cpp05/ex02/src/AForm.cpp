#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const AForm &other) : _name(other.getName()),
								   _isSigned(other.getIsSigned()),
								   _signGrade(other.getSignGrade()),
								   _execGrade(other.getExecGrade())
{
}

AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name),
																	 _isSigned(false),
																	 _signGrade(signGrade),
																	 _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::constructorGradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw AForm::constructorGradeTooLowException();
}

// Destructor
AForm::~AForm()
{
}

// Operator
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other.getIsSigned();
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
		throw AForm::actionGradeTooLowException();
	else
		_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw NotsignedException();
	if (executor.getGrade() > getExecGrade())
		throw actionGradeTooLowException();
	doExecute();
}

// Exceptions
const char *AForm::constructorGradeTooLowException::what() const throw()
{
	return "AForm constructor grade too low (should be <= 150)";
}

const char *AForm::constructorGradeTooHighException::what() const throw()
{
	return "AForm constructor grade too high (should be >= 1)";
}

const char *AForm::actionGradeTooLowException::what() const throw()
{
	return "Higher grade required to sign/execute Form";
}

const char *AForm::NotsignedException::what() const throw()
{
	return "Form must be signed to be executed";
}

// Operator <<
std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "(AForm) name: " << f.getName() << ", isSigned: " << f.getIsSigned() << ", grade(sign, exec): " << f.getSignGrade() << ", " << f.getExecGrade();
	return os;
}
