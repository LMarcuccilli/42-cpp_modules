#include "Bureaucrat.hpp"
#include "AForm.hpp"


// Constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()),
												  _grade(other.getGrade())
{
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	setGrade(grade);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
}

// Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	_grade = other.getGrade();
	return *this;
}

// Getter
const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// Setter
void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

// Function
void Bureaucrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	setGrade(_grade + 1);
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName()<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << f.getName() << " : " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " : " << e.what() << std::endl;
	}
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat constructor Grade too high");
};

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat constructor Grade too low");
};

// Ostream
std::ostream& operator<<(std::ostream &o, const Bureaucrat &a)
{
	o << a.getName() << ", bureaucrat grade " << a.getGrade() << ".";
	return o;
}
