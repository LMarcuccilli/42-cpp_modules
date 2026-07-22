#include "BitcoinExchange.hpp"
#include <cctype>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::ostream &operator<<(std::ostream &os, const Date &date);

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
				throw ParsingException(EXCEP_SEP, lineNb);
			std::string dateStr = line.substr(0, sep);
			std::string valueStr = line.substr(sep + 1);

			Date date = parseDate(dateStr, lineNb);
			std::cout << date << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		lineNb++;
	}
}

Date BitcoinExchange::parseDate(std::string &str, unsigned lineNb) {
	Date date;
	std::istringstream iss(str);
	char c1, c2;

	if (!(iss >> date.year >> c1 >> date.month >> c2 >> date.day))
		throw ParsingException(EXCEP_DATE, lineNb);

	if (c1 != '-' || c2 != '-')
		throw ParsingException(EXCEP_DATE, lineNb);

	return date;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	return os << date.year << '-' << date.day << '-' << date.month;
}
