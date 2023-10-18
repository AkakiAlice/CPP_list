#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

template <typename T, typename Container = std::deque <T> >
class MutantStack : public std::stack <T, Container> {
public:
	MutantStack(void) {};
	MutantStack(const MutantStack & src) {*this = src;};
	~MutantStack(void) {};
	MutantStack& operator=(const MutantStack& rhs) {
		if (this != &rhs)
			std::stack<T, Container>::operator=(rhs);
		return (*this);
	};

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	iterator	begin(void) {
		return this->c.begin();
	}
	iterator	end(void) {
		return this->c.end();
	}
};

#endif
