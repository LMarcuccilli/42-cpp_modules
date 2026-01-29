#pragma once

#include <string>

class AForm;

class Intern
{
public:
	Intern(){}
	~Intern(){}

	AForm *makeForm(const std::string form, const std::string target);
};
