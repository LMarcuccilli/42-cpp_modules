#include "ScalarConverter.hpp"
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>

static void printChar(double x) {
	std::cout << "char: ";
	if (std::isnan(x) || std::isinf(x) ||
		x < 0 || x > 127 || std::floor(x) != x) {
		std::cout << "impossible" <<std::endl;
		return ;
	}

	char c = static_cast<char>(x);

	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "\'" << c << "\'" << std::endl;
	else
		std::cout << "non displayable" << std::endl;

}

static void printInt(double x) {
	std::cout << "int: ";
	if (std::isnan(x) || std::isinf(x) ||
		x < std::numeric_limits<int>::min() ||
		x > std::numeric_limits<int>::max()) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	int i = static_cast<int>(x);
	std::cout << i << std::endl;
}

static void printFloat(double x) {
	float f = static_cast<float>(x);
	std::cout << "float: ";
	if (!std::isnan(f) && !std::isinf(f) && std::floor(f) == f &&
		std::fabs(f) < 1000000.0f)
		std::cout << f << ".0f";
	else
		std::cout << f << "f";
	std::cout << std::endl;
}

static void printDouble(double x) {
	std::cout << "double: ";
	if (!std::isnan(x) && !std::isinf(x) && std::floor(x) == x &&
		std::fabs(x) < 1000000.0)
		std::cout << x << ".0" << std::endl;
	else
		std::cout << x << std::endl;
}

void ScalarConverter::convert(const std::string &lit) {
	if (lit.size() == 0) {
		std::cerr << "Empty parameter" << std::endl;
		return ;
	}

	double value;

	unsigned char uc = static_cast<unsigned char>(lit[0]);
	if (lit.size() == 1 && !std::isdigit(uc) && std::isprint(uc))
		value = lit[0];
	else {
		const char *str = lit.c_str();
		char *end;
		value = std::strtod(str, &end);
		if (end == str || (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))) {
			std::cerr << "Bad parameter" << std::endl;
			return ;
		}
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
