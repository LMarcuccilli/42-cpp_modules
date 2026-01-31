#pragma once

#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat
{
private:
	// parameters
	const std::string _name;
	int _grade;

	// setter
	void setGrade(int grade);

public:
	// constructors
	Bureaucrat();									// default
	Bureaucrat(const Bureaucrat &other);			// copy
	Bureaucrat(int grade);							// grade only
	Bureaucrat(const std::string &name);			// name only
	Bureaucrat(const std::string &name, int grade); // all parameters

	// destructor
	~Bureaucrat();

	// Operator
	Bureaucrat &operator=(const Bureaucrat &other);

	// getter
	const std::string &getName() const;
	int getGrade() const;

	// function
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &f);

	// exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

// ostream
std::ostream &operator<<(std::ostream &o, const Bureaucrat &a);
