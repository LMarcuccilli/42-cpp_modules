#pragma once

#include <string>

class ScalarConverter {
private:
	ScalarConverter();
	~ScalarConverter();

public:
	static void convert(const std::string &lit);
};

