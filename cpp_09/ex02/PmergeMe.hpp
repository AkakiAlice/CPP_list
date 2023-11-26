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
};

#endif
