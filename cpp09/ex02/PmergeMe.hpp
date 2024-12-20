#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "utils.hpp"
# include <iostream>
# include <deque>
# include <list>
# include <algorithm>

# define LIST 0
# define DEQUE 1


class PmergeMe
{
	private:
		std::list<int>	_listA;
		std::list<int>	_listB;
		std::deque<int>	_dequeA;
		std::deque<int>	_dequeB;
		char **_av;
		PmergeMe();

	public:
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

		void	runList();
		void	runDeque();

		void	print(bool c_type);

};

# include "PmergeMe.tpp"


# endif

//	https://www.youtube.com/watch?v=s92Ph6zkRX8
//	https://www.w3resource.com/python-exercises/data-structures-and-algorithms/python-search-and-sorting-exercise-39.php
//	https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort/blob/master/fjmi.py
//	https://github.com/Morwenn/cpp-sort/blob/1.x.y-stable/include/cpp-sort/detail/merge_insertion_sort.h
//