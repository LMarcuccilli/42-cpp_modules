#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>

struct Date {
	unsigned year;
	unsigned day;
	unsigned month;
};

class BitcoinExchange {
  public:
	BitcoinExchange(std::ifstream &input);

  private:
	bool parse(std::ifstream &input);
	std::map<Date, float> _table;
};

#endif
