#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class Rpn {
  private:
	std::stack<int> _stack;

	void operate(const char op);
	class RpnException : public std::exception {
	  public:
		const char *what() const throw() {
			return "Error";
		}
	};

  public:
	Rpn() {}
	~Rpn() {}

	void process(const std::string arg);
};

#endif
