#pragma once
#include <iostream>

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	std::string &getIdea(const int &id);
	void setIdea(const std::string &idea, const int &id);
};
