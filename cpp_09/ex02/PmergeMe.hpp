#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class PmergeMe {
public:
	static void	sort(std::vector<int> input);

private:
	PmergeMe(void);
	PmergeMe(PmergeMe const & src);
	~PmergeMe(void);

	PmergeMe&	operator=(PmergeMe const & rhs);

	static void	merge(std::vector<int> & sequence, int rangeSize);
	//static void	insertionTeste(std::vector<int> & sequence, int rangeSize);

	static std::vector<int>	_sequence;
};

#endif
