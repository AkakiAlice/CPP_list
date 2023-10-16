#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class ValueNotFoundException : public std::exception {
public:
	virtual const char* what(void) const throw() {
		return "Value not found";
	}
};

template <typename T>
typename T::iterator easyfind(T & container, int value) {
	typename T::iterator valueOccurrence;

	valueOccurrence = std::find(container.begin(), container.end(), value);
	if (valueOccurrence == container.end())
		throw ValueNotFoundException();
	return valueOccurrence;
}

#endif
