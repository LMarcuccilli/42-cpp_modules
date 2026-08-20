#include "RPN.hpp"
#include <cctype>
#include <iostream>

void Rpn::operate(const char op) {
	if (_stack.size() <= 1)
		throw RpnException();

	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	if (op == '+') {
		// std::cout << a << op << b << " = " << b + a << std::endl;
		_stack.push(b + a);
	}
	if (op == '-') {
		// std::cout << a << op << b << " = " << b - a << std::endl;
		_stack.push(b - a);
	}
	if (op == '/') {
		if (!a || !b)
			throw RpnException();
		// std::cout << a << op << b << " = " << b / a << std::endl;
		_stack.push(b / a);
	}
	if (op == '*') {
		// std::cout << a << op << b << " = " << b * a << std::endl;
		_stack.push(b * a);
	}
}

void Rpn::process(const std::string arg) {
	for (unsigned i = 0; i < arg.size(); i++) {
		if (std::isdigit(arg[i])) {
			if (i + 1 < arg.size() && std::isdigit(arg[i + 1]))
				throw RpnException();

			_stack.push(arg[i] - '0');
		} else if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' ||
				   arg[i] == '/') {
			if (i + 1 < arg.size() && arg[i + 1] != ' ')
				throw RpnException();
			operate(arg[i]);
		} else if (arg[i] != ' ') {
			throw RpnException();
		}
	}

	if (_stack.size() != 1)
		throw RpnException();

	std::cout << _stack.top() << std::endl;
}
