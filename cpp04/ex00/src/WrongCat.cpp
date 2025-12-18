#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignment constructor" << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		_type = other._type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "wrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat meoow" << std::endl;
}