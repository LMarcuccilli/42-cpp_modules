#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#define EXCEP_FIRSTLINE "expected \"date | value\" as first line"
#define EXCEP_FORMAT "invalid format, expected \"YYYY-MM-DD | value\""
#define EXCEP_DATE "invalid date format, expected YYYY-MM-DD"
#define EXCEP_VALUE "invalid value"

struct Date {
	unsigned year;
	unsigned day;
	unsigned month;
};

std::ostream &operator<<(std::ostream &os, const Date &date);

class BitcoinExchange {
  public:
	BitcoinExchange(std::ifstream &input);

  private:
	std::map<Date, double> _table;
	bool parse(std::ifstream &input);
	void parseLine(std::string &str, unsigned lineNb);
	void printTable() const;

	// Exception
	class ParsingException : public std::runtime_error {
	  public:
		ParsingException(const std::string &msg, unsigned line)
			: std::runtime_error(makeMessage(msg, line)) {}

	  private:
		static std::string makeMessage(const std::string &msg, unsigned line) {
			std::ostringstream oss;
			oss << "line " << line << ": " << msg;
			return oss.str();
		}
	};
};

#endif
