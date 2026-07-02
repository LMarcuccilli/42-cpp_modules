#include "BitcoinExchange.hpp"
#include <cstddef>
#include <iostream>
#include <exception>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange(std::ifstream &input) {
	if (!parse(input))
		throw std::exception();
}

static void printError(int line, const std::string message) {
	std::cerr << "line " << line << ": " << message << std::endl;
}

bool BitcoinExchange::parse(std::ifstream &input) {
	bool formatted = true;
	int lineNumber = 1;
	std::string line;
	std::getline(input, line);

	if (line != "date | value") {
		printError(lineNumber, "first line should describe \"date | value\"");
		formatted = false;
	}
	std::size_t pos;
	while (std::getline(input, line)) {
		lineNumber++;
		pos = line.find('|');

		if (pos == std::string::npos) {
			printError(lineNumber, "couldn't find '|' separator");
			formatted = false;
			continue;
		}
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 1);

		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(0, date.find_last_not_of(" \t") + 1);

		value.erase(0, date.find_first_not_of(" \t"));
		value.erase(0, date.find_last_not_of(" \t") + 1);

		std::cout << date << std::endl;
		std::cout << value << std::endl;
	}


	return formatted;
}
