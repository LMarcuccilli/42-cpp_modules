#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment constructor" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}
