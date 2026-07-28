#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class EasyfindException : public std::exception {
  public:
	virtual const char *what() const throw() { return "value not found"; }
};

template <typename T>
typename T::iterator easyfind(T &arr, int value) {
	typename T::iterator it = std::find(arr.begin(), arr.end(), value);

	if (it == arr.end())
		throw EasyfindException();

	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &arr, int value) {
	typename T::const_iterator it = std::find(arr.begin(), arr.end(), value);

	if (it == arr.end())
		throw EasyfindException();

	return it;
}
#endif
