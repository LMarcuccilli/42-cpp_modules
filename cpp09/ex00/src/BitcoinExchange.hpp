#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#define EXCEP_FIRSTLINE "expected \"date | value\" as first line"
#define EXCEP_SEP "missing \'|\' character"
#define EXCEP_DATE "invalid date format, expected YYYY-MM-DD"

struct Date {
	unsigned year;
	unsigned day;
	unsigned month;
};

class BitcoinExchange {
  public:
	BitcoinExchange(std::ifstream &input);

  private:
	std::map<Date, float> _table;
	bool parse(std::ifstream &input);
	Date parseDate(std::string &str, unsigned lineNb);

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
