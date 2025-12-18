#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog contructor" << std::endl;
	_brain = new Brain();
	_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor" << std::endl;
	_brain = new Brain(*other._brain);
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment constructor" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
		_type = other._type;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "woof !" << std::endl;
}

Brain &Dog::getBrain(void) const
{
	return *_brain;
}
