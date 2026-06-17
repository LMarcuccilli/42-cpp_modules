#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>

void ScalarConverter::convert(const std::string &lit) {
	char *c;
	double value = std::strtod(lit.c_str(), &c);
	std::cout << value << std::endl;
}
