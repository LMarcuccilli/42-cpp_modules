#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int ac, char *av[]) {
	(void)ac;
	for (int i = 1; av[i]; i++)
	{
		std::string arg(av[i]);
		ScalarConverter::convert(arg);
		std::cout << "--------------------\n";
	}

	return 0 ;
}
