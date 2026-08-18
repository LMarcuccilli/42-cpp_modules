#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdexcept>

enum e_type {
	num,
	op,
	other
};

class Rpn {
  private:
	std::stack<int> _stack;

	int getType(const char c);
	void operate(const char op);
	class RpnException : public std::runtime_error {
	  public:
		RpnException(const std::string msg) : std::runtime_error(msg) {}
	};

  public:
	Rpn() {}
	~Rpn() {}

	void process(const std::string arg);
};

#endif
