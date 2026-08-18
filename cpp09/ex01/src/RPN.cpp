#include "RPN.hpp"
#include <cctype>
#include <exception>

int Rpn::getType(const char c) {
	if (std::isdigit(c))
		return e_type::num;
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return e_type::op;
	return e_type::other;
}

void Rpn::operate(const char op) {
	if (_stack.size() <= 1)
		throw std::exception();

	if (op == '+') {
		
	}
}

void Rpn::process(const std::string arg) {
	for (int i = 0; i < arg.size(); i++) {
		switch (getType(arg[i])) {
			case e_type::num :
				_stack.push(arg[i] - '0');
				break;
			case e_type::op :

				break;
		}
	}
}
