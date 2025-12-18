#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment constructor" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

std::string &Brain::getIdea(const int &id)
{
	if (id >= 0 && id < 100)
		return _ideas[id];
	return _ideas[0];
}

void Brain::setIdea(const std::string &idea, const int &id)
{
	if (id >= 0 && id < 100)
		_ideas[id] = idea;
}
