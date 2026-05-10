#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main(void)
{
	srand(time(0));

	std::cout << "================== random ptr " << std::endl;
	Base *ptr;
	for (size_t i = 0; i < 3; i++) {
		ptr = generate();
		identify(ptr);
		std::cout << "-------" << std::endl;
		delete ptr;
	}

	std::cout << "================== random ref" << std::endl;
	Base *ref;
	for (size_t i = 0; i < 3; i++) {
		ref = generate();
		identify(*ref);
		std::cout << "-------" << std::endl;
		delete ref;
	}

	std::cout << "================== ABC" << std::endl;
	Base *a = new A();
	identify(a);
	delete a;

	Base *b = new B();
	identify(b);
	delete b;

	Base *c = new C();
	identify(c);
	delete c;

	return 0;
}
