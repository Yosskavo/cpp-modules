#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
	private :
		std::vector<int>	_vector;
		std::deque<int>		_deque;
	public  :
		PmergeMe(void);
		PmergeMe(const PmergeMe &p);
		PmergeMe &operator=(const PmergeMe & p);
		~PmergeMe(void);
		void	print_it(void);
		void	InsertElements(const char **av);
		void	SortVector(void);
		void	SortDeque(void);
};

#endif
