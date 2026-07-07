#include "../include/Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned N) : _size(N), _filled(0) { _array = new int[_size]; }

Span::Span(const Span &other) : _size(other._size), _filled(other._filled) {
	_array = new int[_size];

	for (unsigned i = 0; i < _filled; i++) {
		_array[i] = other._array[i];
	}
}

void Span::addNumber(int v) {
	if (_filled == _size)
		throw FullException();

	_array[_filled] = v;
	_filled++;
}

long long Span::shortestSpan() {
	if (_filled <= 1)
		throw EmptyException();

	int *newArray = new int[_filled];
	std::copy(_array, _array + _filled, newArray);
	std::sort(newArray, newArray + _filled);

	long long tmpRes = 0;
	long long result = std::numeric_limits<long long>::max();
	for (unsigned i = 1; i < _filled; i++) {
		tmpRes = static_cast<long long>(newArray[i]) - static_cast<long long>(newArray[i - 1]);
		if (tmpRes < result)
			result = tmpRes;
	}

	delete[] newArray;
	return result;
}

long long Span::longestSpan() {
	if (_filled <= 1)
		throw EmptyException();

	int *newArray = new int[_filled];
	std::copy(_array, _array + _filled, newArray);
	std::sort(newArray, newArray + _filled);

	long long res =
		static_cast<long long>(newArray[_filled - 1]) - static_cast<long long>(newArray[0]);
	delete[] newArray;
	return res;
}
