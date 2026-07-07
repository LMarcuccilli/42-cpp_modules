#include "BitcoinExchange.hpp"
#include <cctype>
#include <exception>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange(std::ifstream &input) {
	std::string firstLine;
	std::getline(input, firstLine);
	if (firstLine != "date | value")
		throw std::exception();

	for (std::string line; std::getline(input, line);) {
		try {
			std::size_t sep = line.find('|');
			if (sep == std::string::npos)
				throw std::exception();
			std::string date = line.substr(0, sep);
			std::string value = line.substr(sep + 1);
		}
		catch (...) {

		}
	}
}

static void parseLine(std::string &line) {
	
}
