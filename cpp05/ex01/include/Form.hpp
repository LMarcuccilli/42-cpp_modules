#pragma once

#include <string>

class Bureaucrat;

class Form
{
private:
	// params
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;

public:
	// constructor
	Form();
	Form(const Form &other);
	Form(int signGrade, int execGrade);
	Form(const std::string name);
	Form(const std::string name, int signGrade, int execGrade);

	// destructor
	~Form();

	// operator =
	Form &operator=(const Form &other);

	// getter
	const std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getIsSigned() const;

	// functions
	void beSigned(const Bureaucrat &b);

	// exceptions
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

// operator <<
std::ostream &operator<<(std::ostream &os, const Form &f);