#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#define EXCEP_FIRSTLINE "expected \"date | value\" as first line"
#define EXCEP_INPUT "bad input"
#define EXCEP_DATE "invalid date format, expected YYYY-MM-DD"
#define EXCEP_VALUE_HIGH "too large a number"
#define EXCEP_VALUE_NEG "not a positive number"

struct Date {
	unsigned year;
	unsigned day;
	unsigned month;
};

std::ostream &operator<<(std::ostream &os, const Date &date);
bool operator<(const Date& lhs, const Date& rhs);

class BitcoinExchange {
  public:
	BitcoinExchange(std::ifstream &input);

  private:
	std::map<Date, double> _table;
	bool parse(std::ifstream &input);
	void parseLine(const std::string &line);
	void printTable() const;

	// Exception
	class ParsingException : public std::runtime_error {
	  public:
		ParsingException(const std::string &msg)
			: std::runtime_error(makeMessage(msg)) {}
		ParsingException(const std::string &msg, std::string input)
			: std::runtime_error(makeMessage(msg, input)) {}

	  private:
		static std::string makeMessage(const std::string &msg) {
			std::ostringstream oss;
			oss << "Error: " << msg;
			return oss.str();
		}
		static std::string makeMessage(const std::string &msg, std::string input) {
			std::ostringstream oss;
			oss << "Error: " << msg << " => " << "\"" << input << "\"";
			return oss.str();
		}
	};
};

#endif
