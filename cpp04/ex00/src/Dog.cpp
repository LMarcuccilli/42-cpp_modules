#include "Dog.hpp"

Dog::Dog(): Animal() {
	_type = "Dog";
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other) {
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		_type = other._type;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof !" << std::endl;
}