#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
	int randomNum = rand() % 3;

	if (randomNum == 0) {
		std::cout << "generated A" << std::endl;
		return new A();
	}
	else if (randomNum == 1) {
		std::cout << "generated B" << std::endl;
		return new B();
	}
	else {
		std::cout << "generated C" << std::endl;
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "identify * A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "identify * B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "identify * C" << std::endl;
}

void identify(Base &p) {

	try {
		dynamic_cast<A &>(p);
		std::cout << "identify & A" << std::endl;
	}
	catch (...) {}

	try {
		dynamic_cast<B &>(p);
		std::cout << "identify & B" << std::endl;
	}
	catch (...) {}

	try {
		dynamic_cast<C &>(p);
		std::cout << "identify & C" << std::endl;
	}
	catch (...) {}
}
