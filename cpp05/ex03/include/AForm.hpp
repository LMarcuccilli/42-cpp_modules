#pragma once

#include <string>

class Bureaucrat;

class AForm
{
private:
	// params
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;

public:
	// constructor
	AForm();
	AForm(const AForm &other);
	AForm(const std::string name, int signGrade, int execGrade);

	// destructor
	virtual ~AForm();

	// operator =
	AForm &operator=(const AForm &other);

	// getter
	const std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getIsSigned() const;

	// functions
	void beSigned(const Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;
	virtual void doExecute() const = 0;

	// exceptions
	class constructorGradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class constructorGradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class actionGradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NotsignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

// operator <<
std::ostream &operator<<(std::ostream &os, const AForm &f);
