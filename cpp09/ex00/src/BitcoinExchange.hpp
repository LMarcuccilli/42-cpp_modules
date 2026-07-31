#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

// PATH
#define DATA_PATH "data.csv"

// EXCEPTION
#define EXCEP_OPEN "couldn't access"
#define EXCEP_DATA "corrupted data.csv"
#define EXCEP_FIRSTLINE "expected \"date | value\" as first line"
#define EXCEP_INPUT "bad input"
#define EXCEP_DATE "invalid date format, expected YYYY-MM-DD"
#define EXCEP_VALUE_HIGH "too large a number"
#define EXCEP_VALUE_NEG "not a positive number"

// DATE
struct Date {
	int year;
	int month;
	int day;
};
std::ostream &operator<<(std::ostream &os, const Date &date);
bool operator<(const Date &lhs, const Date &rhs);

struct InputEntry {
	Date date;
	double value;
};

// CLASS
class BitcoinExchange {
  public:
	BitcoinExchange(char *input);

  private:
	std::map<Date, double> _table;
	void storeData(std::ifstream &input);
	void solveInput(std::ifstream &input);
	bool parse(std::ifstream &input);
	InputEntry parseLine(const std::string &line);
	std::map<Date, double>::iterator &findLowerData(Date &d);
	void printTable() const;

	// Exception
	class BitcoinExchangeException : public std::runtime_error {
	  public:
		BitcoinExchangeException(const std::string &msg)
			: std::runtime_error(makeMessage(msg)) {}
		BitcoinExchangeException(const std::string &msg, std::string input)
			: std::runtime_error(makeMessage(msg, input)) {}

	  private:
		static std::string makeMessage(const std::string &msg) {
			std::ostringstream oss;
			oss << "Error: " << msg;
			return oss.str();
		}
		static std::string makeMessage(const std::string &msg,
									   std::string input) {
			std::ostringstream oss;
			oss << "Error: " << msg << " => "
				<< "\"" << input << "\"";
			return oss.str();
		}
	};
};

#endif
