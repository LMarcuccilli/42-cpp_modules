#include "Animal.hpp"

Animal::Animal(): _type("Animal") {
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "unknown sound..." << std::endl;
}