#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <fstream>

class BitcoinExchange {
  public:
	BitcoinExchange(std::ifstream &input);

  private:
	bool parse(std::ifstream &input);
	std::map<int[3], float> _table;
};

#endif
