#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor" << std::endl;
	_brain = new Brain();
	_type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor" << std::endl;
	_brain = new Brain(*other._brain);
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignement constructor" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
		_type = other._type;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "meow !" << std::endl;
}

Brain &Cat::getBrain(void) const
{
	return *_brain;
}
