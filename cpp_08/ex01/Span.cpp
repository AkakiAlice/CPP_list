#include "Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(Span const & src) {
	*this = src;
}

Span::~Span(void) {}

Span&	Span::operator=(Span const & rhs) {
	this->_maxSize = rhs._maxSize;
	this->_vector = rhs._vector;
	return *this;
}

char const *Span::SpanOverflowException::what(void) const throw() {
	return "Span has already reached its maximum size";
}

char const *Span::NotEnoughElementsException::what(void) const throw() {
	return "Span doesn't have enough elements to compare";
}

void	Span::addNumber(int const & value) {
	if (_vector.size() == _maxSize)
		throw SpanOverflowException();
	_vector.push_back(value);
}

int	Span::shortestSpan(void) {
	if (_vector.size() < 2)
		throw NotEnoughElementsException();

	std::sort(_vector.begin(), _vector.end());

	int shortestSpan = std::numeric_limits<int>::max();
	for (size_t i = 2; i < _vector.size(); i++) {
			if (_vector[i] - _vector[i - 1] < shortestSpan)
				shortestSpan = _vector[i] - _vector[i - 1];
	}
	return shortestSpan;
}

int	Span::longestSpan(void) {
	int minElement = *std::min_element(_vector.begin(), _vector.end());
	int maxElement = *std::max_element(_vector.begin(), _vector.end());

	return (maxElement - minElement);
}

void	Span::addNumberRange(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	if (std::distance(first, last) + _vector.size() > _maxSize)
		throw SpanOverflowException();
	_vector.insert(_vector.end(), first, last);
}

int	Span::getElement(int i) {
	return _vector[i];
}
