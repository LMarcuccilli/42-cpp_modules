#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cout << "Usage: btc inputFile" << std::endl;
		return 1;
	}

	std::ifstream file(av[1]);
	if (!file) {
		std::cerr << "Failed to open" << av[1] << std::endl;
		return 1;
	}

	BitcoinExchange btc(file);

	return 0;
}
