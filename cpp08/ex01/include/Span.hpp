#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iterator>

class Span {
  public:
	Span(unsigned N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span() { delete[] _array; }

	void addNumber(int);

	long long shortestSpan();
	long long longestSpan();

	template <typename Iterator> void addNumbers(Iterator begin, Iterator end) {
		int count = std::distance(begin, end);
		if (count < 0)
			throw ReverseIteratorException();
		if (_filled + static_cast<unsigned>(count) > _size)
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
		virtual const char *what() const throw() {
			return ("Span array is already full");
		}
	};
	class NotEnoughElementsException : public std::exception {
	  public:
		virtual const char *what() const throw() {
			return ("Span array size < 2, no span can be found");
		}
	};
	class ReverseIteratorException : public std::exception {
	  public:
		virtual const char *what() const throw() {
			return ("Reverse Iterator not managed");
		}
	};
};

#endif
