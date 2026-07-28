#include "../include/Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	try {
		std::cout << "=== Subject test ===" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "=== Large test ===" << std::endl;
		const unsigned int SIZE = 10000;
		int values[SIZE];

		std::srand(std::time(NULL));

		for (unsigned i = 0; i < SIZE; i++) {
			values[i] = std::rand();
		}

		Span bigSpan(SIZE);

		bigSpan.addNumbers(values, values + SIZE);

		std::cout << bigSpan.shortestSpan() << std::endl;
		std::cout << bigSpan.longestSpan() << std::endl;

		std::cout << "=== Exception test ===" << std::endl;
		bigSpan.addNumber(42);

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
