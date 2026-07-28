#include "../include/Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned N) : _size(N), _filled(0) { _array = new int[_size]; }

Span::Span(const Span &other) : _size(other._size), _filled(other._filled) {
	_array = new int[_size];

	std::copy(other._array, other._array + _filled, _array);
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		int *tmp = new int[other._size];
		std::copy(other._array, other._array + other._filled, tmp);

		delete[] _array;

		_size = other._size;
		_filled = other._filled;
		_array = tmp;
	}
	return *this;
}

void Span::addNumber(int v) {
	if (_filled == _size)
		throw FullException();

	_array[_filled] = v;
	_filled++;
}

long long Span::shortestSpan() {
	if (_filled <= 1)
		throw NotEnoughElementsException();

	int *newArray = new int[_filled];
	std::copy(_array, _array + _filled, newArray);
	std::sort(newArray, newArray + _filled);

	long long result = std::numeric_limits<long long>::max();
	for (unsigned i = 1; i < _filled; i++) {
		long long tmpRes = static_cast<long long>(newArray[i]) -
						   static_cast<long long>(newArray[i - 1]);
		if (tmpRes < result)
			result = tmpRes;
	}

	delete[] newArray;
	return result;
}

long long Span::longestSpan() {
	if (_filled <= 1)
		throw NotEnoughElementsException();

	int *newArray = new int[_filled];
	std::copy(_array, _array + _filled, newArray);
	std::sort(newArray, newArray + _filled);

	long long res = static_cast<long long>(newArray[_filled - 1]) -
					static_cast<long long>(newArray[0]);
	delete[] newArray;
	return res;
}
