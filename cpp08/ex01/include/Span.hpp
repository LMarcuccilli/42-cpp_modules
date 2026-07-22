#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iterator>

class Span {
  public:
	Span(unsigned N);
	Span(const Span &other);
	~Span() { delete[] _array; }

	void addNumber(int);

	long long shortestSpan();
	long long longestSpan();

	template <typename Iterator> void addNumbers(Iterator begin, Iterator end) {
		if (_filled + std::distance(begin, end) > _size)
			throw FullException();

		while (begin != end)
			addNumber(*begin++);
	}

  private:
	unsigned _size;
	unsigned _filled;
	int *_array;

	class FullException : public std::exception {
	  public:
		virtual const char *what() const throw() { return ("Span array is already full"); }
	};
	class EmptyException : public std::exception {
	  public:
		virtual const char *what() const throw() {
			return ("Span array size < 2, no span can be found");
		}
	};
};

#endif
