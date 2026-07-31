#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(char *input) {
	std::ifstream dataFile(DATA_PATH);
	if (!dataFile)
		throw BitcoinExchangeException(EXCEP_OPEN, DATA_PATH);
	storeData(dataFile);

	std::ifstream inputFile(input);
	if (!inputFile)
		throw BitcoinExchangeException(EXCEP_OPEN, input);
	solveInput(inputFile);
}

void BitcoinExchange::storeData(std::ifstream &input) {
	std::string firstLine;
	std::getline(input, firstLine);

	for (std::string line; std::getline(input, line);) {
		Date date;
		char c1, c2, c3;
		double value;
		std::istringstream iss(line);

		if (!(iss >> date.year >> c1 >> date.month >> c2 >> date.day >> c3 >> value))
			throw BitcoinExchangeException(EXCEP_DATA);
		if (c1 != '-' || c2 != '-' || c3 != ',')
			throw BitcoinExchangeException(EXCEP_DATA);
		_table.insert(std::make_pair(date, value));
	}
}

void BitcoinExchange::solveInput(std::ifstream &input) {
	std::string firstLine;
	std::getline(input, firstLine);
	try {
		if (firstLine != "date | value")
			throw BitcoinExchangeException(EXCEP_FIRSTLINE);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return;
	}

	for (std::string line; std::getline(input, line);) {
		try {
			InputEntry entry = parseLine(line);

			std::map<Date, double>::iterator it = _table.lower_bound(entry.date);

			std::cout << entry.date << " => " << it->second << " = " << entry.value * it->second << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

InputEntry BitcoinExchange::parseLine(const std::string &line) {
	if (line.size() < 14 || line[4] != '-' || line[7] != '-' ||
		line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw BitcoinExchangeException(EXCEP_INPUT, line);

	// YYYY
	for (unsigned i = 0; i < 4; i++) {
		if (!std::isdigit(line[i]))
			throw BitcoinExchangeException(EXCEP_INPUT, line);
	}
	// MM
	for (unsigned i = 5; i < 7; i++) {
		if (!std::isdigit(line[i]))
			throw BitcoinExchangeException(EXCEP_INPUT, line);
	}
	// DD
	for (unsigned i = 8; i < 10; i++) {
		if (!std::isdigit(line[i]))
			throw BitcoinExchangeException(EXCEP_INPUT, line);
	}

	Date date;
	date.year = std::atoi(line.substr(0, 4).c_str());
	date.month = std::atoi(line.substr(5, 2).c_str());
	date.day = std::atoi(line.substr(8, 2).c_str());

	// VALUE
	char *end;
	const std::string valueString = line.substr(13);
	const char *lineValue = valueString.c_str();
	double value = std::strtod(line.substr(13).c_str(), &end);
	if (end == lineValue || (!std::isdigit(*end) && *end != '\0'))
		throw BitcoinExchangeException(EXCEP_INPUT, line);

	if (value < 0)
		throw BitcoinExchangeException(EXCEP_VALUE_NEG);
	if (value > 1000)
		throw BitcoinExchangeException(EXCEP_VALUE_HIGH);

	InputEntry result;
	result.date = date;
	result.value = value;
	return result;
}

std::map<Date, double>::iterator &bitcoinExchange::findLowerData(Date &d) {

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
