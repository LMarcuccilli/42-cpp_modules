#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
  private:
	// parameters
	const std::string _name;
	int _grade;

	// setter
	void setGrade(int grade);

  public:
	// constructors
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(const std::string &name, int grade);

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

	// exceptions
	class GradeTooHighException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};
};

// ostream
std::ostream &operator<<(std::ostream &o, const Bureaucrat &a);
