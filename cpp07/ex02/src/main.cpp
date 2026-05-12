#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	std::cout << "===== INT ARRAY =====" << std::endl;

	Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	std::cout << std::endl;


	std::cout << "===== COPY CONSTRUCTOR =====" << std::endl;

	Array<int> copy(numbers);

	copy[0] = 999;

	std::cout << "Original array:" << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << "Copied array:" << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl << std::endl;


	std::cout << "===== ASSIGNMENT OPERATOR =====" << std::endl;

	Array<int> assigned;

	assigned = numbers;

	assigned[1] = 555;

	std::cout << "Original array:" << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << "Assigned array:" << std::endl;
	for (unsigned int i = 0; i < assigned.size(); i++)
		std::cout << assigned[i] << " ";
	std::cout << std::endl << std::endl;


	std::cout << "===== STRING ARRAY =====" << std::endl;

	Array<std::string> words(3);

	words[0] = "hello";
	words[1] = "template";
	words[2] = "world";

	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << std::endl;

	std::cout << std::endl;


	std::cout << "===== OUT OF BOUNDS =====" << std::endl;

	try
	{
		std::cout << numbers[42] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: index out of bounds" << std::endl;
	}

	return 0;
}
