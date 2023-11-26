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

/* ---------------------------------------------------------------------*\
|							SORT VECTOR									|
\* ---------------------------------------------------------------------*/

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

void	fillPendAndChain(std::vector<int> & pend, std::vector<int> & chain, std::vector<int> & sequence, int rangeSize) {
	int	sequenceSize = sequence.size() / (rangeSize * 2);
	int	i = 0;

	std::vector<int>::iterator	firstRange1 = sequence.begin();
	std::vector<int>::iterator	lastRange1 = firstRange1 + rangeSize;

	std::vector<int>::iterator	firstRange2 = lastRange1;
	std::vector<int>::iterator	lastRange2 = firstRange2 + rangeSize;

	while (firstRange1 != sequence.end()) {
		if (i == sequenceSize) {
			while (firstRange1 != sequence.end()) {
				pend.push_back(*firstRange1);
				firstRange1++;
			}
			break;
		}
		pend.insert(pend.end(), firstRange1, lastRange1);
		chain.insert(chain.end(), firstRange2, lastRange2);

		firstRange1 = lastRange2;
		lastRange1 = firstRange1 + rangeSize;

		firstRange2 = lastRange1;
		lastRange2 = firstRange2 + rangeSize;
		i++;
	}
}

void	comparePairs(std::vector<int> & sequence, int rangeSize) {
	int	sequenceSize = sequence.size() / (rangeSize * 2);
	int	i = 0;
	int	maxValueRange1;
	int	maxValueRange2;

	std::vector<int>::iterator	firstRange1 = sequence.begin();
	std::vector<int>::iterator	lastRange1 = firstRange1 + rangeSize;

	std::vector<int>::iterator	firstRange2 = lastRange1;
	std::vector<int>::iterator	lastRange2 = firstRange2 + rangeSize;

	while (i != sequenceSize) {
		maxValueRange1 = *std::max_element(firstRange1, lastRange1);
		maxValueRange2 = *std::max_element(firstRange2, lastRange2);
		if (maxValueRange1 > maxValueRange2)
			std::swap_ranges(firstRange1, lastRange1, firstRange2);

		firstRange1 = lastRange2;
		lastRange1 = firstRange1 + rangeSize;

		firstRange2 = lastRange1;
		lastRange2 = firstRange2 + rangeSize;
		i++;

	}
}

void	mergeInsertionSort(std::vector<int> & sequence, int rangeSize) {
	if (rangeSize >= static_cast<int>(sequence.size()))
		return ;

	comparePairs(sequence, rangeSize);
	mergeInsertionSort(sequence, rangeSize * 2);

	std::vector<int>	pend;
	std::vector<int>	chain;
	std::vector<int>	sorted;
	fillPendAndChain(pend, chain, sequence, rangeSize);
	insertionSort(chain, pend, sorted, rangeSize);
	sequence.assign(sorted.begin(), sorted.end());
}

void	PmergeMe::sort(std::vector<int> & input) {
	mergeInsertionSort(input, 1);
}


/* ---------------------------------------------------------------------*\
|							SORT DEQUE									|
\* ---------------------------------------------------------------------*/

int binarySearch(const std::deque<int>& deque, int value) {
	int	first = 0;
	int	last = deque.size() - 1;

	while (first <= last) {
		int	middle = (first + last) / 2;

		if (deque[middle] == value)
			return middle;
		else if (deque[middle] < value)
			first = middle + 1;
		else
			last = middle - 1;
	}

	return first;
}

void	goToNextRange(std::deque<int>::iterator & first, std::deque<int>::iterator & last, int rangeSize) {
	first = last;
	last = first + rangeSize;
}

void	findRangeByPosition (std::deque<int>::iterator & first, std::deque<int>::iterator & last, std::deque<int> & deque, int pos, int rangeSize) {
	std::deque<int>::iterator	it = deque.begin();
	std::deque<int>::iterator	itE = it + rangeSize;
	for (int i = 1; i < pos; i++)
		goToNextRange(it, itE, rangeSize);
	first = it;
	last = itE;
}

void	getSearchDeque(std::deque<int> & chain, std::deque<int> & sorted, int pos, std::deque<int> & searchDeque, int rangeSize) {
	std::deque<int>::iterator	firstSorted = sorted.begin();
	std::deque<int>::iterator	lastSorted = firstSorted + rangeSize;

	if (pos >= static_cast<int>(chain.size() / rangeSize)) {
		while (firstSorted != sorted.end()) {
			searchDeque.push_back(*(std::max_element(firstSorted, lastSorted)));
			goToNextRange(firstSorted, lastSorted, rangeSize);
		}
		return ;
	}

	std::deque<int>::iterator	firstChain;
	std::deque<int>::iterator	lastChain;
	findRangeByPosition(firstChain, lastChain, chain, pos, rangeSize);

	while (*firstSorted != *firstChain) {
		searchDeque.push_back(*(std::max_element(firstSorted, lastSorted)));
		goToNextRange(firstSorted, lastSorted, rangeSize);
	}
}

int	getRangeMaxValue (std::deque<int> & deque, int pos, int rangeSize) {
	std::deque<int>::iterator	first;
	std::deque<int>::iterator	last;
	findRangeByPosition(first, last, deque, pos, rangeSize);
	return *(std::max_element(first, last));
}

void insertionSort(std::deque<int> & chain, std::deque<int> & pend, std::deque<int> & sorted, int rangeSize) {

	sorted = chain;
	std::vector<int>			insertionSequence;
	std::deque<int>::iterator	firstPend = pend.begin();
	std::deque<int>::iterator	lastPend = firstPend + rangeSize;
	std::deque<int>::iterator	it;
	std::deque<int>::iterator	ite;

	getInsertionSequence(pend.size() / rangeSize, insertionSequence);

	int	i = 0;
	int	pendSize = pend.size() / (rangeSize);
	int	pos;
	while (i != pendSize) {
		if (firstPend == pend.begin())
			sorted.insert(sorted.begin(), firstPend, lastPend);
		else {
			std::deque<int>	searchDeque;
			getSearchDeque(chain, sorted, insertionSequence[i], searchDeque, rangeSize);
			pos = binarySearch(searchDeque, getRangeMaxValue(pend, insertionSequence[i], rangeSize));
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

void	fillPendAndChain(std::deque<int> & pend, std::deque<int> & chain, std::deque<int> & sequence, int rangeSize) {
	int	sequenceSize = sequence.size() / (rangeSize * 2);
	int	i = 0;

	std::deque<int>::iterator	firstRange1 = sequence.begin();
	std::deque<int>::iterator	lastRange1 = firstRange1 + rangeSize;

	std::deque<int>::iterator	firstRange2 = lastRange1;
	std::deque<int>::iterator	lastRange2 = firstRange2 + rangeSize;

	while (firstRange1 != sequence.end()) {
		if (i == sequenceSize) {
			while (firstRange1 != sequence.end()) {
				pend.push_back(*firstRange1);
				firstRange1++;
			}
			break;
		}
		pend.insert(pend.end(), firstRange1, lastRange1);
		chain.insert(chain.end(), firstRange2, lastRange2);

		firstRange1 = lastRange2;
		lastRange1 = firstRange1 + rangeSize;

		firstRange2 = lastRange1;
		lastRange2 = firstRange2 + rangeSize;
		i++;
	}
}

void	comparePairs(std::deque<int> & sequence, int rangeSize) {
	int	sequenceSize = sequence.size() / (rangeSize * 2);
	int	i = 0;
	int	maxValueRange1;
	int	maxValueRange2;

	std::deque<int>::iterator	firstRange1 = sequence.begin();
	std::deque<int>::iterator	lastRange1 = firstRange1 + rangeSize;

	std::deque<int>::iterator	firstRange2 = lastRange1;
	std::deque<int>::iterator	lastRange2 = firstRange2 + rangeSize;

	while (i != sequenceSize) {
		maxValueRange1 = *std::max_element(firstRange1, lastRange1);
		maxValueRange2 = *std::max_element(firstRange2, lastRange2);
		if (maxValueRange1 > maxValueRange2)
			std::swap_ranges(firstRange1, lastRange1, firstRange2);

		firstRange1 = lastRange2;
		lastRange1 = firstRange1 + rangeSize;

		firstRange2 = lastRange1;
		lastRange2 = firstRange2 + rangeSize;
		i++;

	}
}

void	mergeInsertionSort(std::deque<int> & sequence, int rangeSize) {
	if (rangeSize >= static_cast<int>(sequence.size()))
		return ;

	comparePairs(sequence, rangeSize);
	mergeInsertionSort(sequence, rangeSize * 2);

	std::deque<int>	pend;
	std::deque<int>	chain;
	std::deque<int>	sorted;
	fillPendAndChain(pend, chain, sequence, rangeSize);
	insertionSort(chain, pend, sorted, rangeSize);
	sequence.assign(sorted.begin(), sorted.end());
}

void	PmergeMe::sort(std::deque<int> & input) {
	mergeInsertionSort(input, 1);
}

































































// int binarySearch(const std::list<int>& list, int value) {
// 	std::list<int>::const_iterator first = list.begin();
// 	std::list<int>::const_iterator last = list.end();  // último elemento

// 	while (first != ++last) {
// 		std::list<int>::const_iterator middle = first;
// 		std::advance(middle, std::distance(first, last) / 2);

// 		if (*middle == value)
// 			return std::distance(list.begin(), middle);
// 		else if (*middle < value)
// 			first = middle;
// 		else
// 			last = middle;
// 	}

// 	return std::distance(list.begin(), first);
// }

// void	goToNextRange(std::list<int>::iterator & first, std::list<int>::iterator & last, int rangeSize) {
// 	first = last;
// 	last = first;
// 	std::advance(last, rangeSize);
// }

// void	findRangeByPosition (std::list<int>::iterator & first, std::list<int>::iterator & last, std::list<int> & list, int pos, int rangeSize) {
// 	std::list<int>::iterator	it = list.begin();
// 	std::list<int>::iterator	itE = it;
// 	std::advance(itE, rangeSize);
// 	for (int i = 1; i < pos; i++)
// 		goToNextRange(it, itE, rangeSize);
// 	first = it;
// 	last = itE;
// }

// void	getSearchList(std::list<int> & chain, std::list<int> & sorted, int pos, std::list<int> & searchList, int rangeSize) {
// 	std::list<int>::iterator	firstSorted = sorted.begin();
// 	std::list<int>::iterator	lastSorted = firstSorted;
// 	std::advance(firstSorted, rangeSize);

// 	if (pos >= static_cast<int>(chain.size() / rangeSize)) {
// 		while (firstSorted != sorted.end()) {
// 			searchList.push_back(*(std::max_element(firstSorted, lastSorted)));
// 			goToNextRange(firstSorted, lastSorted, rangeSize);
// 		}
// 		return ;
// 	}

// 	std::list<int>::iterator	firstChain;
// 	std::list<int>::iterator	lastChain;
// 	findRangeByPosition(firstChain, lastChain, chain, pos, rangeSize);

// 	while (*firstSorted != *firstChain) {
// 		searchList.push_back(*(std::max_element(firstSorted, lastSorted)));
// 		goToNextRange(firstSorted, lastSorted, rangeSize);
// 	}
// }

// int	getRangeMaxValue (std::list<int> & list, int pos, int rangeSize) {
// 	std::list<int>::iterator	first;
// 	std::list<int>::iterator	last;
// 	findRangeByPosition(first, last, list, pos, rangeSize);
// 	return *(std::max_element(first, last));
// }

// void insertionSort(std::list<int> & chain, std::list<int> & pend, std::list<int> & sorted, int rangeSize) {

// 	sorted = chain;
// 	std::vector<int>			insertionSequence;
// 	std::list<int>::iterator	firstPend = pend.begin();
// 	std::list<int>::iterator	lastPend = firstPend;
// 	std::advance(lastPend, rangeSize);
// 	std::list<int>::iterator	it;
// 	std::list<int>::iterator	ite;

// 	getInsertionSequence(pend.size() / rangeSize, insertionSequence);

// 	int	i = 0;
// 	int	pendSize = pend.size() / (rangeSize);
// 	int	pos;
// 	while (i != pendSize) {
// 		if (firstPend == pend.begin())
// 			sorted.insert(sorted.begin(), firstPend, lastPend);
// 		else {
// 			std::list<int>	searchList;
// 			std::list<int>::iterator insertionPos = sorted.begin();
// 			getSearchList(chain, sorted, insertionSequence[i], searchList, rangeSize);
// 			pos = binarySearch(searchList, getRangeMaxValue(pend, insertionSequence[i], rangeSize));
// 			findRangeByPosition(it, ite, pend, insertionSequence[i], rangeSize);
// 			std::advance(insertionPos, pos * rangeSize);
// 			sorted.insert(insertionPos, it, ite);
// 		}
// 		goToNextRange(firstPend, lastPend, rangeSize);
// 		i++;
// 	}
// 	while (firstPend != pend.end()) {
// 		sorted.push_back(*firstPend);
// 		firstPend++;
// 	}
// }

// void	fillPendAndChain(std::list<int> & pend, std::list<int> & chain, std::list<int> & sequence, int rangeSize) {
// 	int	sequenceSize = sequence.size() / (rangeSize * 2);
// 	int	i = 0;

// 	std::list<int>::iterator	firstRange1 = sequence.begin();
// 	std::list<int>::iterator	lastRange1 = firstRange1;
// 	std::advance(lastRange1, rangeSize);

// 	std::list<int>::iterator	firstRange2 = lastRange1;
// 	std::list<int>::iterator	lastRange2 = firstRange2;
// 	std::advance(lastRange2, rangeSize);

// 	while (firstRange1 != sequence.end()) {
// 		if (i == sequenceSize) {
// 			while (firstRange1 != sequence.end()) {
// 				pend.push_back(*firstRange1);
// 				firstRange1++;
// 			}
// 			break;
// 		}
// 		pend.insert(pend.end(), firstRange1, lastRange1);
// 		chain.insert(chain.end(), firstRange2, lastRange2);

// 		firstRange1 = lastRange2;
// 		lastRange1 = firstRange1;
// 		std::advance(lastRange1, rangeSize);

// 		firstRange2 = lastRange1;
// 		lastRange2 = firstRange2;
// 		std::advance(lastRange2, rangeSize);
// 		i++;
// 	}
// }

// void	comparePairs(std::list<int> & sequence, int rangeSize) {
// 	int	sequenceSize = sequence.size() / (rangeSize * 2);
// 	int	i = 0;
// 	int	maxValueRange1;
// 	int	maxValueRange2;

// 	std::list<int>::iterator	firstRange1 = sequence.begin();
// 	std::list<int>::iterator	lastRange1 = firstRange1;
// 	std::advance(lastRange1, rangeSize);

// 	std::list<int>::iterator	firstRange2 = lastRange1;
// 	std::list<int>::iterator	lastRange2 = firstRange2;
// 	std::advance(lastRange2, rangeSize);

// 	while (i != sequenceSize) {
// 		maxValueRange1 = *std::max_element(firstRange1, lastRange1);
// 		maxValueRange2 = *std::max_element(firstRange2, lastRange2);
// 		if (maxValueRange1 > maxValueRange2)
// 			std::swap_ranges(firstRange1, lastRange1, firstRange2);

// 		firstRange1 = lastRange2;
// 		lastRange1 = firstRange1;
// 		std::advance(lastRange1, rangeSize);

// 		firstRange2 = lastRange1;
// 		lastRange2 = firstRange2;
// 		std::advance(lastRange1, rangeSize);
// 		i++;

// 	}
// }

// void	mergeInsertionSort(std::list<int> & sequence, int rangeSize) {
// 	if (rangeSize >= static_cast<int>(sequence.size()))
// 		return ;

// 	comparePairs(sequence, rangeSize);
// 	mergeInsertionSort(sequence, rangeSize * 2);

// 	std::list<int>	pend;
// 	std::list<int>	chain;
// 	std::list<int>	sorted;
// 	fillPendAndChain(pend, chain, sequence, rangeSize);
// 	insertionSort(chain, pend, sorted, rangeSize);
// 	sequence.assign(sorted.begin(), sorted.end());
// }

// void	PmergeMe::sort(std::list<int> & input) {
// 	mergeInsertionSort(input, 1);
// }
