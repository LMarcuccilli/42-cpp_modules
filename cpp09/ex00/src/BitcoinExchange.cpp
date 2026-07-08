#include "BitcoinExchange.hpp"
#include <cctype>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static Date parseDate(std::string &date);
std::ostream &operator<<(std::ostream &os, const Date &date);

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
			std::string dateStr = line.substr(0, sep);
			std::string valueStr = line.substr(sep + 1);

			Date date = parseDate(dateStr);
			std::cout << date << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what();
		}
	}
}

static Date parseDate(std::string &str) {
	Date date;
	std::istringstream iss(str);
	char c1, c2;

	if (!(iss >> date.year >> c1 >> date.day >> c2 >> date.month))
		throw std::exception();

	if (c1 != '-' || c2 != '-')
		throw std::exception();

	return date;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	return os << date.year << '-' << date.day << '-' << date.month;
}
