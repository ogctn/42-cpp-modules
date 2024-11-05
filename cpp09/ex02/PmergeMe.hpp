#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <list>

bool	isOnlyDigits(const char *);

class PmergeMe
{
	private:
		std::list< std::pair<int,int> >		_list;
		std::deque< std::pair<int,int> >	_deque;
		size_t	_size;


	public:
		PmergeMe();
		PmergeMe(char *av[]);
		~PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

		std::list< std::pair<int,int> >		&getList();
		std::deque< std::pair<int,int> >	&getDeque();
		size_t			getSize();

		# include "PmergeMe.tpp"

	private:
		void	fillData(char *av[]);
		void	pushPair(int, int);



};


# endif

//	https://www.youtube.com/watch?v=s92Ph6zkRX8
//	https://www.w3resource.com/python-exercises/data-structures-and-algorithms/python-search-and-sorting-exercise-39.php
//	https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort/blob/master/fjmi.py
//	https://github.com/Morwenn/cpp-sort/blob/1.x.y-stable/include/cpp-sort/detail/merge_insertion_sort.h
//