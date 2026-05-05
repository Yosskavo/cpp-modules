#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
	private :
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double				_time_vector;
		double				_time_deque;
		std::vector<int>::iterator	FindPos(int value);	
	public  :
		PmergeMe(void);
		PmergeMe(const PmergeMe &p);
		PmergeMe &operator=(const PmergeMe & p);
		~PmergeMe(void);
		void	print_it(const std::string &str);
		void	InsertElements(const char **av);
		void	SortVector(void);
		void	SortDeque(void);
		void	print_time(const std::string & str) const;
};

#endif
