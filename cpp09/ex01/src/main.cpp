#include "RPN.hpp"
#include <iostream>

int main(int ac, char *av[]) {
	if (ac < 2) {
		std::cerr << "Error: 1 argument required" << std::endl;
		return 1;
	}

	try {
		Rpn rpn;
		rpn.process(av[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
