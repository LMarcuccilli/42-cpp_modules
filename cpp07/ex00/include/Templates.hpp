#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

// SWAP
template <typename T>
void swap(T &a, T &b) {
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

// MIN
template <typename T>
const T &min(const T &a, const T &b) {
	if (a < b)
		return a;
	return b;
}

// MAX
template <typename T>
const T &max(const T &a, const T &b) {
	if (a > b)
		return a;
	return b;
}

#endif
