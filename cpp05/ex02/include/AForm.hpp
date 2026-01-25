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

	// helper function
	void checkGrade(const int garde, const int minGrade) const;

public:
	// constructor
	AForm();
	AForm(const AForm &other);
	AForm(const std::string name, int signGrade, int execGrade);

	// destructor
	virtual ~AForm();

	// operator
	AForm &operator=(const AForm &other);

	// getter
	const std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getIsSigned() const;

	// functions
	virtual void beSigned(const Bureaucrat &b);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class NotsignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
