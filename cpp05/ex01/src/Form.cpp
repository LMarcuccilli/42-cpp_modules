#include "Form.hpp"
#include "Bureaucrat.hpp"

// helper function
static void checkGrade(const int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

// Constructor
Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

Form::Form(const Form &other) : _name(other.getName()),
								_isSigned(other.getIsSigned()),
								_signGrade(other.getSignGrade()),
								_execGrade(other.getExecGrade())
{
}

Form::Form(int signGrade, int execGrade) : _name("default"),
										   _isSigned(false),
										   _signGrade(signGrade),
										   _execGrade(execGrade)
{
	checkGrade(_signGrade);
	checkGrade(_execGrade);
}

Form::Form(const std::string name) : _name(name),
									 _isSigned(false),
									 _signGrade(150),
									 _execGrade(150)
{
}

Form::Form(const std::string name, int signGrade, int execGrade) : _name(name),
																   _isSigned(false),
																   _signGrade(signGrade),
																   _execGrade(execGrade)
{
	checkGrade(_signGrade);
	checkGrade(_execGrade);
}

// Destructor
Form::~Form()
{
}

// Operator =
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other.getIsSigned();
	return *this;
}

// Getter
const std::string Form::getName() const
{
	return _name;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

// Functions
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		_isSigned = true;
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high (must be >= 1)";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low (must be <= 150)";
}

// Operator <<
std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "(Form) name: " << f.getName() << ", isSigned: " << f.getIsSigned() << ", grade(sign, exec): " << f.getSignGrade() << ", " << f.getExecGrade();
	return os;
}
