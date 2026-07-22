#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {

  public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef
		typename std::stack<T>::container_type::const_iterator const_iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const iterator begin() const { return this->c.begin(); }
	const iterator end() const { return this->c.end(); }
};

#endif
