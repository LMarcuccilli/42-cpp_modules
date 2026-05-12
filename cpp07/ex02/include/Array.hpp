#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T> class Array {
  private:
	T *_arr;
	unsigned int _size;

  public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	~Array();

	unsigned int size() const;
	T &operator[](unsigned int index);
	T &operator[](unsigned int index) const;
	Array<T> &operator=(const Array<T> &other);
};

// CONSTRUCTOR
template <typename T> Array<T>::Array() : _arr(0), _size(0) {}

template <typename T> Array<T>::Array(unsigned int n) : _size(n) {
	_arr = new T[_size];
}

template <typename T> Array<T>::Array(const Array &other) : _size(other._size) {
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = other._arr[i];
}

// DESTRUCTOR
template <typename T> Array<T>::~Array() { delete[] _arr; }

// FUNCTIONS
template <typename T> unsigned int Array<T>::size() const { return _size; }

// OPERATOR
// []
template <typename T> T &Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::exception();

	return _arr[index];
}

// [] const
template <typename T> T &Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::exception();

	return _arr[index];
}

// =
template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		delete[] _arr;
		_size = other._size;
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

#endif
