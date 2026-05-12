#include <iostream>
#include <string>
#include "Iter.hpp"

void addOne(int &n)
{
	n++;
}

void printInt(const int &n)
{
	std::cout << n << " ";
}

void printString(const std::string &str)
{
	std::cout << str << std::endl;
}

void toUpper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

void doubleValue(float &f)
{
	f *= 2;
}

void printFloat(const float &f)
{
	std::cout << f << " ";
}

int main(void)
{
	std::cout << "===== INT ARRAY =====" << std::endl;

	int intArr[] = {1, 2, 3, 4, 5};

	std::cout << "Before: ";
	iter(intArr, 5, printInt);
	std::cout << std::endl;

	iter(intArr, 5, addOne);

	std::cout << "After : ";
	iter(intArr, 5, printInt);
	std::cout << std::endl << std::endl;


	std::cout << "===== STRING ARRAY =====" << std::endl;

	std::string strArr[] = {
		"hello",
		"world",
		"template",
		"iter"
	};

	std::cout << "Before:" << std::endl;
	iter(strArr, 4, printString);

	iter(strArr, 4, toUpper);

	std::cout << "\nAfter:" << std::endl;
	iter(strArr, 4, printString);

	std::cout << std::endl;


	std::cout << "===== FLOAT ARRAY =====" << std::endl;

	float floatArr[] = {1.1f, 2.2f, 3.3f};

	std::cout << "Before: ";
	iter(floatArr, 3, printFloat);
	std::cout << std::endl;

	iter(floatArr, 3, doubleValue);

	std::cout << "After : ";
	iter(floatArr, 3, printFloat);
	std::cout << std::endl;

	return 0;
}
