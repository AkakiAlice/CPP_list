#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe&	PmergeMe::operator=(PmergeMe const & rhs) {
	(void)rhs;
	return *this;
}

void	printRange(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	for (std::vector<int>::iterator it = first; it != last; it++) {
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;
}

void	printVector(std::vector<int> vector) {
	std::vector<int>::iterator	first = vector.begin();
	std::vector<int>::iterator	last = vector.end();
	printRange(first, last);
}

int	jacobsthal(int n) {
	if (n == 0 || n == 1) return n;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void	getInsertionSequence(size_t pendSize, std::vector<int> & insertionSequence) {
	int		n = 0;
	size_t	result;
	size_t	prevResult;
	size_t	aux;

	result = jacobsthal(n);
	prevResult = result;
	while (1) {
		++n;
		prevResult = result;
		result = jacobsthal(n);
		aux = result;

		while (aux > prevResult) {
			while (aux > pendSize) {
				--aux;
			}
			insertionSequence.push_back(aux);
			if (aux == pendSize) {
				while (aux - 1 > prevResult)
					insertionSequence.push_back(--aux);
				return;
			}
			--aux;
		}

	}
}

bool is_sorted(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if (first == last)
		return true;

	std::vector<int>::iterator	next = first;
	while (++next != last) {
		if (*next < *first)
			return false;
		++first;
	}
	return true;
}

void	PmergeMe::sort(std::vector<int> input) {
	merge(input, 1);
	printVector(input);
	if (is_sorted(input.begin(), input.end()))
		std::cout << "Is sorted\n";
}

int binarySearch(const std::vector<int>& vector, int value) {
	int	first = 0;
	int	last = vector.size() - 1;

	while (first <= last) {
		int	middle = (first + last) / 2;

		if (vector[middle] == value)
			return middle;
		else if (vector[middle] < value)
			first = middle + 1;
		else
			last = middle - 1;
	}

	return first;
}

void	goToNextRange(std::vector<int>::iterator & first, std::vector<int>::iterator & last, int rangeSize) {
	first = last;
	last = first + rangeSize;
}

void	findRangeByPosition (std::vector<int>::iterator & first, std::vector<int>::iterator & last, std::vector<int> & vector, int pos, int rangeSize) {
	std::vector<int>::iterator	it = vector.begin();
	std::vector<int>::iterator	itE = it + rangeSize;
	for (int i = 1; i < pos; i++)
		goToNextRange(it, itE, rangeSize);
	first = it;
	last = itE;
}

void	getSearchVector(std::vector<int> & chain, std::vector<int> & sorted, int pos, std::vector<int> & searchVector, int rangeSize) {
	std::vector<int>::iterator	firstSorted = sorted.begin();
	std::vector<int>::iterator	lastSorted = firstSorted + rangeSize;

	if (pos >= static_cast<int>(chain.size() / rangeSize)) {
		while (firstSorted != sorted.end()) {
			searchVector.push_back(*(std::max_element(firstSorted, lastSorted)));
			goToNextRange(firstSorted, lastSorted, rangeSize);
		}
		return ;
	}

	std::vector<int>::iterator	firstChain;
	std::vector<int>::iterator	lastChain;
	findRangeByPosition(firstChain, lastChain, chain, pos, rangeSize);

	while (*firstSorted != *firstChain) {
		searchVector.push_back(*(std::max_element(firstSorted, lastSorted)));
		goToNextRange(firstSorted, lastSorted, rangeSize);
	}
}

int	getRangeMaxValue (std::vector<int> & vector, int pos, int rangeSize) {
	std::vector<int>::iterator	first;
	std::vector<int>::iterator	last;
	findRangeByPosition(first, last, vector, pos, rangeSize);
	return *(std::max_element(first, last));
}

void insertionSort(std::vector<int> & chain, std::vector<int> & pend, std::vector<int> & sorted, int rangeSize) {

	sorted = chain;
	std::vector<int>			insertionSequence;
	std::vector<int>::iterator	firstPend = pend.begin();
	std::vector<int>::iterator	lastPend = firstPend + rangeSize;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite;

	getInsertionSequence(pend.size() / rangeSize, insertionSequence);

	int	i = 0;
	int	pendSize = pend.size() / (rangeSize);
	int	pos;
	while (i != pendSize) {
		if (firstPend == pend.begin())
			sorted.insert(sorted.begin(), firstPend, lastPend);
		else {
			std::vector<int>	searchVector;
			getSearchVector(chain, sorted, insertionSequence[i], searchVector, rangeSize);
			pos = binarySearch(searchVector, getRangeMaxValue(pend, insertionSequence[i], rangeSize));
			findRangeByPosition(it, ite, pend, insertionSequence[i], rangeSize);
			sorted.insert(sorted.begin() + (pos * rangeSize), it, ite);
		}
		goToNextRange(firstPend, lastPend, rangeSize);
		i++;
	}
	while (firstPend != pend.end()) {
		sorted.push_back(*firstPend);
		firstPend++;
	}
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


	std::vector<int>	insertionSequence;
	std::vector<int>	pend;
	std::vector<int>	chain;


	j = sequence.size() / (rangeSize * 2);
	if (j == 0)
		return;

	firstRange1 = sequence.begin();
	lastRange1 = firstRange1 + rangeSize;

	firstRange2 = lastRange1;
	lastRange2 = firstRange2 + rangeSize;

	i = 0;

	while (firstRange1 != sequence.end()) {
		if (i == j) {
			while (firstRange1 != sequence.end()) {
				pend.push_back(*firstRange1);
				firstRange1++;
			}
			break;
		}
		maxRange1 = *std::max_element(firstRange1, lastRange1);
		maxRange2 = *std::max_element(firstRange2, lastRange2);
		pend.insert(pend.end(), firstRange1, lastRange1);
		chain.insert(chain.end(), firstRange2, lastRange2);

		firstRange1 = lastRange2;
		lastRange1 = firstRange1 + rangeSize;

		firstRange2 = lastRange1;
		lastRange2 = firstRange2 + rangeSize;
		i++;

	}
	std::vector<int> sorted;
	insertionSort(chain, pend, sorted, rangeSize);
	sequence.assign(sorted.begin(), sorted.end());
}
