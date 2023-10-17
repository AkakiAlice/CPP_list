#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>

class Span {
public:
	Span(void);
	Span(unsigned int N);
	Span(Span const & src);
	~Span(void);

	Span&	operator=(Span const & rhs);

	class SpanOverflowException : public std::exception {
	public:
		virtual const char* what(void) const throw();
	};

	class NotEnoughElementsException : public std::exception {
	public:
		virtual const char* what(void) const throw();
	};

	void	addNumber(int const & value);

	int	shortestSpan(void);
	int	longestSpan(void);

	int	getElement(int i);

	void	addNumberRange(std::vector<int>::iterator first, std::vector<int>::iterator last);

private:
	unsigned int		_maxSize;
	std::vector<int>	_vector;
};

#endif
