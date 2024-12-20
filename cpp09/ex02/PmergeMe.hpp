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
		std::list<int>	_listA, _listB;
		std::deque<int>	_dequeA, _dequeB;
		char **_av;
		PmergeMe();

	public:
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

		std::list<int>	&getListA();

		void	runList();
		void	runDeque();

};

# include "PmergeMe.tpp"


# endif

//	https://www.youtube.com/watch?v=s92Ph6zkRX8
//	https://www.w3resource.com/python-exercises/data-structures-and-algorithms/python-search-and-sorting-exercise-39.php
//	https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort/blob/master/fjmi.py
//	https://github.com/Morwenn/cpp-sort/blob/1.x.y-stable/include/cpp-sort/detail/merge_insertion_sort.h
//