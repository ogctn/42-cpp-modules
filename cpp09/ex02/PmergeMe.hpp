#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <list>

# define LIST 0
# define DEQUE 1

bool	isOnlyDigits(const char *);

class PmergeMe
{
	private:
		std::list<int>	_list_first;
		std::list<int>	_list_second;
		std::deque<int>	_deque_first;
		std::deque<int>	_deque_second;

	private:
		void	pushPair(int val1, int val2, bool flag);

	public:
		PmergeMe();
		PmergeMe(char *av[]);
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

		void	print(bool flag);
		void	print();

		void	fillData(char *av[], bool flag);


};

# include "PmergeMe.tpp"


# endif

//	https://www.youtube.com/watch?v=s92Ph6zkRX8
//	https://www.w3resource.com/python-exercises/data-structures-and-algorithms/python-search-and-sorting-exercise-39.php
//	https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort/blob/master/fjmi.py
//	https://github.com/Morwenn/cpp-sort/blob/1.x.y-stable/include/cpp-sort/detail/merge_insertion_sort.h
//