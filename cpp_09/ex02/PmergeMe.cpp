#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::_sequence;

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe&	PmergeMe::operator=(PmergeMe const & rhs) {
	(void)rhs;
	return *this;
}

std::vector<int>::iterator	middle(std::vector<int>::iterator it, std::vector<int>::iterator itEnd) {
	std::vector<int>::iterator middle = it + std::distance(it, ++itEnd) / 2;
    return middle;
}



void	printRange(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	for (std::vector<int>::iterator it = first; it != last; it++) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;
}

void	printRangeInfo(std::vector<int>::iterator first, std::vector<int>::iterator last, std::string rangeName) {
	std::cout << "range " << rangeName << "\n";
	std::cout << "first:      [" << *first << "]\n";
	std::cout << "last:       [" << *last << "]\n";
	std::cout << "range size: [" << std::distance(first, last) << "]\n";
	std::cout << "range:      ";
	printRange(first, last);
}

void	printVector(std::vector<int> vector) {
	std::vector<int>::iterator first = vector.begin();
	std::vector<int>::iterator last = vector.end();
	printRange(first, last);
}

void	PmergeMe::sort(std::vector<int> input) {
	merge(input, 1);
	//printRange(input.begin(), input.end());
}


void	PmergeMe::merge(std::vector<int> & sequence, int rangeSize) {

	if (rangeSize >= static_cast<int>(sequence.size()))
		return ;

	size_t	j = sequence.size() / (rangeSize * 2);

	std::vector<int>::iterator	firstRange1 = sequence.begin();
	std::vector<int>::iterator	lastRange1 = firstRange1 + rangeSize;

	std::vector<int>::iterator	firstRange2 = lastRange1;
	std::vector<int>::iterator	lastRange2 = firstRange2 + rangeSize;

	int		maxRange1;
	int		maxRange2;
	size_t	i = 0;

	while (firstRange1 != sequence.end()) {
		if (i == j)
			break;
		maxRange1 = *std::max_element(firstRange1, lastRange1);
		maxRange2 = *std::max_element(firstRange2, lastRange2);
		if (maxRange1 > maxRange2)
			std::swap_ranges(firstRange1, lastRange1, firstRange2);

		firstRange1 = lastRange2;
		lastRange1 = firstRange1 + rangeSize;

		firstRange2 = lastRange1;
		lastRange2 = firstRange2 + rangeSize;
		i++;

	}

	merge(sequence, rangeSize * 2);



	std::vector<int> pend;
	std::vector<int> chain;


	j = sequence.size() / (rangeSize * 2);

	firstRange1 = sequence.begin();
	lastRange1 = firstRange1 + rangeSize;

	firstRange2 = lastRange1;
	lastRange2 = firstRange2 + rangeSize;

	i = 0;
	std::cout << rangeSize << std::endl;

	while (firstRange1 != sequence.end()) {
		if (i == j)
			break;
		maxRange1 = *std::max_element(firstRange1, lastRange1);
		maxRange2 = *std::max_element(firstRange2, lastRange2);
		pend.push_back(maxRange1);
		chain.push_back(maxRange2);

		firstRange1 = lastRange2;
		lastRange1 = firstRange1 + rangeSize;

		firstRange2 = lastRange1;
		lastRange2 = firstRange2 + rangeSize;
		i++;

	}
	printVector(chain);
	printVector(pend);
	std::cout << "\n\n\n";
}

