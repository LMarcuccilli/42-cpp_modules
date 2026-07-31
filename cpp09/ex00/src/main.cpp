#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cout << "Usage: btc inputFile" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc(av[1]);
	}
	catch (const std::exception &e) {
		std::cerr << e.what();
	}

return 0;
}
