#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <cwctype>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(std::ifstream &input) {
	unsigned lineNb = 1;
	std::string firstLine;
	std::getline(input, firstLine);
	try {
		if (firstLine != "date | value")
			throw ParsingException(EXCEP_FIRSTLINE, lineNb);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return;
	}

	lineNb++;
	for (std::string line; std::getline(input, line);) {
		try {
			std::size_t sep = line.find('|');
			if (sep == std::string::npos)
				throw ParsingException(EXCEP_FORMAT, lineNb);
			std::string dateStr = line.substr(0, sep);
			std::string valueStr = line.substr(sep + 1);

			parseLine(dateStr, lineNb);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		lineNb++;
	}
	printTable();
}

void BitcoinExchange::parseLine(std::string &str, unsigned lineNb) {
	Date date;

	unsigned i = 0;
	for (unsigned y = 0; y < 4; y++) {
		if (!std::isdigit(str[i]))
			throw ParsingException(EXCEP_FORMAT, lineNb);
		i++;
	}
	if (str[i++] != '-')
		throw ParsingException(EXCEP_FORMAT, lineNb);
	for (unsigned y = 0; y < 2; y++) {
		if (!std::isdigit(str[i]))
			throw ParsingException(EXCEP_FORMAT, lineNb);
		i++;
	}
	if (str[i++] != '-')
		throw ParsingException(EXCEP_FORMAT, lineNb);
	for (unsigned y = 0; y < 2; y++) {
		if (!std::isdigit(str[i]))
			throw ParsingException(EXCEP_FORMAT, lineNb);
		i++;
	}
	if (str[i++] != ' ' && str[i++] != '|' && str[i++] != ' ' && i < str.size())
		throw ParsingException(EXCEP_FORMAT, lineNb);
	bool dot = false;
	while (i < str.size()) {
		if (str[i] == '.') {
			if (dot || ++i == str.size())
				throw ParsingException(EXCEP_VALUE, lineNb);
			dot = true;
		}
		if (!std::isdigit(str[i]))
			throw ParsingException(EXCEP_VALUE, lineNb);
		i++;
	}

	date.year = std::atoi(str.substr(0, 4).c_str());
	date.month = std::atoi(str.substr(5, 2).c_str());
	date.day = std::atoi(str.substr(8, 2).c_str());
	char *end;
	double value = std::strtod(str.substr(12).c_str(), &end);
	_table.insert((std::make_pair(date, value)));
}

void BitcoinExchange::printTable() const {
	std::map<Date, double>::const_iterator it;

	for (it = _table.begin(); it != _table.end(); ++it) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	std::cout << std::setw(4) << std::setfill('0') << date.year;
	std::cout << "-" << std::setw(2) << std::setfill('0') << date.month;
	std::cout << "-" << std::setw(2) << std::setfill('0') << date.day;
	return os;
}
