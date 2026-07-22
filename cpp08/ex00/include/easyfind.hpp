#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class EasyfindException : public std::exception {
  public:
	virtual const char *what() const throw() { return "value not found"; }
};

template <typename T> int easyfind(T &arr, int value) {
	typename T::iterator it = std::find(arr.begin(), arr.end(), value);

	if (it == arr.end())
		throw EasyfindException();
	return *it;
}

#endif
