#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
public:
	Array(void) : _size(0), _array(NULL) {
		std::cout << "Array: default constructor called" << std::endl;
	};

	Array(unsigned int n) : _size(n), _array(new T[_size]) {
		std::cout << "Array: parametric constructor called" << std::endl;
	};

	Array(Array const & src) :  _size(src._size), _array(new T[_size]) {
		*this = src;
		std::cout << "Array: copy constructor called" << std::endl;
	};

	~Array(void) {
		delete[] _array;
		std::cout << "Array: destructor called" << std::endl;
	};

	Array<T>&	operator=(Array const & rhs) {
		if (this->_array)
			delete[] this->_array;
		this->_size = rhs.size();
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++) {
			this->_array[i] = rhs._array[i];
		}
		return *this;
	}

	T&	operator[](unsigned int const index) {
		if (index >= _size)
			throw std::out_of_range("Index is out of range");
		return this->_array[index];
	}

	unsigned int size(void) const{
		return this->_size;
	}

private:
	unsigned int	_size;
	T*				_array;
};

#endif
