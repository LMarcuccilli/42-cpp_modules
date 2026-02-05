#include <iostream>
#include <cstdlib>
#include <cmath>
#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

static void printChar(int c, bool possible)
{
	std::cout << "char: ";
	if (!possible || c < 0)
		std::cout << "impossible\n";
	else if (!isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
}

static void printInt(int c, bool possible)
{
	std::cout << "int: ";
	if (!possible)
		std::cout << "impossible\n";
	else
		std::cout << c << std::endl;
}

static void printFloat(float f, bool possible)
{
	std::cout << "float: ";
	if (!possible)
		std::cout << "impossible\n";
	else
	{
		if (std::isnan(f) || std::isinf(f))
			std::cout << f << "f" << std::endl;
		else if (f == std::floor(f))
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}
}

static void printDouble(double d, bool possible)
{
	std::cout << "double: ";
	if (!possible)
		std::cout << "impossible\n";
	else
	{
		if (std::isnan(d) || std::isinf(d))
			std::cout << d << std::endl;
		else if (d == std::floor(d))
			std::cout << d << ".0" << std::endl;
		else
			std::cout << d << std::endl;
	}
}

static bool isPseudoLit(const std::string &lit)
{
	const std::string pseudoLit[8] = {
		"nan",
		"nanf",
		"-inf",
		"-inff",
		"inf",
		"+inf",
		"inff",
		"+inff"
	};

	for (int i = 0; i < 8; i++)
	{
		if (lit == pseudoLit[i])
			return true ;
	}
	return false ;
}

// Convert function
void ScalarConverter::convert(const std::string &lit)
{ 
	if (isPseudoLit(lit))
	{
		char *end;
		double d = std::strtod(lit.c_str(), &end);
		printChar(' ', false);
		printInt(0, false);
		printFloat(static_cast<float>(d), true);
		printDouble(d, true);
	}
	else
	{
		char *end;
		double d = std::strtod(lit.c_str(), &end);
		printChar(static_cast<int>(d), true);
		printInt(static_cast<int>(d), true);
		printFloat(static_cast<float>(d), true);
		printDouble(d, true);
	}
}

