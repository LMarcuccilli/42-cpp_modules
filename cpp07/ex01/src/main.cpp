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

void toUpper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

void printString(const std::string &str)
{
	std::cout << str << " ";
}

int main()
{
	int numbers[] = {1, 2, 3};
	std::string words[] = {"hello", "world"};

	::iter(numbers, 3, printInt);
	std::cout << std::endl;

	::iter(numbers, 3, addOne);
	::iter(numbers, 3, printInt);
	std::cout << std::endl;

	::iter(words, 2, printString);
	std::cout << std::endl;

	::iter(words, 2, toUpper);
	::iter(words, 2, printString);
	std::cout << std::endl;

	return 0;
}
