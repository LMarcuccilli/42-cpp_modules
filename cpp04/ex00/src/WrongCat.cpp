#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat constructed" << std::endl;

}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other) {
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		_type = other._type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "wrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat meoow" << std::endl;
}