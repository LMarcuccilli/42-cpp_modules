#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

template <typename T>
int easyfind(T arr, int value) {
	for (unsigned i = 0; i < arr.size(); i++) {
		if (arr[i] == value)
			return arr[i];
	}

	throw std::exception();
}


#endif
