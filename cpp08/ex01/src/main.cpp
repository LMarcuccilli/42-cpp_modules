#include "../include/Span.hpp"

int main() {
	{
		int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		Span sp = Span(5);
		sp.addNumbers(array, array + 10);
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}
