#include "../include/ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

static void printChar(int c, bool possible) {
	std::cout << "char: ";
	if (!possible || c < 0 || c > 127)
		std::cout << "impossible\n";
	else if (!isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
}

static void printInt(int c, bool possible) {
	std::cout << "int: ";
	if (!possible)
		std::cout << "impossible\n";
	else
		std::cout << c << std::endl;
}

static void printFloat(float f, bool possible) {
	std::cout << "float: ";
	if (!possible)
		std::cout << "impossible\n";
	else {
		if (std::isnan(f) || std::isinf(f))
			std::cout << f << "f" << std::endl;
		else if (f == std::floor(f) && std::fabs(f) < 1e6)
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}
}

static void printDouble(double d, bool possible) {
	std::cout << "double: ";
	if (!possible)
		std::cout << "impossible\n";
	else {
		if (std::isnan(d) || std::isinf(d))
			std::cout << d << std::endl;
		else if (d == std::floor(d) && std::fabs(d) < 1e6)
			std::cout << d << ".0" << std::endl;
		else
			std::cout << d << std::endl;
	}
}

static bool isPseudoLit(const std::string &lit) {
	const std::string pseudoLit[8] = {"nan", "nanf", "-inf", "-inff",
	                                  "inf", "+inf", "inff", "+inff"};

	for (int i = 0; i < 8; i++) {
		if (lit == pseudoLit[i])
			return true;
	}
	return false;
}

// Convert function
void ScalarConverter::convert(const std::string &lit) {

	bool charPossible = true;
	bool intPossible = true;
	bool floatPossible = true;
	bool doublePossible = true;

	char *end;
	double d;
	if (lit.length() == 1 && !std::isdigit(lit[0]))
		d = static_cast<double>(lit[0]);
	else {
		d = std::strtod(lit.c_str(), &end);
		if (*end == 'f' && *(end + 1) == '\0')
		{}
		else if (*end != '\0' && !isPseudoLit(lit)) {
			charPossible = intPossible = floatPossible = doublePossible = false;
		}
	}

	if (d < std::numeric_limits<int>::min() ||
	    d > std::numeric_limits<int>::max() || std::isnan(d))
		intPossible = false;

	if (!intPossible || d < 0 || d > 127)
		charPossible = false;

	if (!std::isinf(d) && !std::isnan(d) &&
		std::fabs(d) > std::numeric_limits<float>::max())
		floatPossible = false;

	if (lit.size() == 0)
		charPossible = intPossible = floatPossible = doublePossible = false;

	printChar(static_cast<int>(d), charPossible);
	printInt(static_cast<int>(d), intPossible);
	printFloat(static_cast<float>(d), floatPossible);
	printDouble(d, doublePossible);
}
