#include "../include/easyfind.hpp"
#include <deque>
#include <exception>
#include <iostream>
#include <vector>

int main(void) {
	std::cout << "=== Vector Test ===" << std::endl;
	std::vector<int> arrV;
	arrV.push_back(1);
	arrV.push_back(2);
	arrV.push_back(3);

	try {
		std::cout << *::easyfind(arrV, 1) << std::endl;
		std::cout << *::easyfind(arrV, 3) << std::endl;
		std::cout << *::easyfind(arrV, 42) << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "=== Deqeue Test ===" << std::endl;
	std::deque<int> arrD;
	arrD.push_back(1);
	arrD.push_back(2);
	arrD.push_back(3);

	try {
		std::cout << *::easyfind(arrD, 1) << std::endl;
		std::cout << *::easyfind(arrD, 3) << std::endl;
		std::cout << *::easyfind(arrD, 42) << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
