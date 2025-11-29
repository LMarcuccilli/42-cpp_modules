#include "Cat.hpp"

Cat::Cat(): Animal() {
	_type = "Cat";
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other) {
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		_type = other._type;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow !" << std::endl;
}