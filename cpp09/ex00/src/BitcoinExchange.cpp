#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(std::ifstream &input) {
	std::string firstLine;
	std::getline(input, firstLine);
	try {
		if (firstLine != "date | value")
			throw ParsingException(EXCEP_FIRSTLINE);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return;
	}

	for (std::string line; std::getline(input, line);) {
		try {
			parseLine(line);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::parseLine(const std::string &line) {
	if (line.size() < 14 || line[4] != '-' || line[7] != '-' ||
		line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw ParsingException(EXCEP_INPUT, line);

	// YYYY
	for (unsigned i = 0; i < 4; i++) {
		if (!std::isdigit(line[i]))
			throw ParsingException(EXCEP_INPUT, line);
	}
	// MM
	for (unsigned i = 5; i < 7; i++) {
		if (!std::isdigit(line[i]))
			throw ParsingException(EXCEP_INPUT, line);
	}
	// DD
	for (unsigned i = 8; i < 10; i++) {
		if (!std::isdigit(line[i]))
			throw ParsingException(EXCEP_INPUT, line);
	}

	// VALUE
	char *end;
	const std::string valueString = line.substr(13);
	const char *lineValue = valueString.c_str(); 
	double value = std::strtod(line.substr(13).c_str(), &end);
	if (end == lineValue)
		throw ParsingException(EXCEP_INPUT, line);

	if (value < 0)
		throw ParsingException(EXCEP_VALUE_NEG);
	if (value > 1000)
		throw ParsingException(EXCEP_VALUE_HIGH);

	std::cout << line << std::endl;
}

void BitcoinExchange::printTable() const {
	std::map<Date, double>::const_iterator it;

	for (it = _table.begin(); it != _table.end(); ++it) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
}

bool operator<(const Date &lhs, const Date &rhs) {
	if (lhs.year != rhs.year)
		return lhs.year < rhs.year;
	if (lhs.month != rhs.month)
		return lhs.month < rhs.month;
	return lhs.day < rhs.day;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << std::setw(4) << std::setfill('0') << date.year;
	os << "-" << std::setw(2) << std::setfill('0') << date.month;
	os << "-" << std::setw(2) << std::setfill('0') << date.day;
	return os;
}
