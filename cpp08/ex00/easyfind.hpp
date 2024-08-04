#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <map>


template <typename T>
int easyfind(const T &c, int to_find);


template <typename Value>
int easyfind(const std::map<int,Value> &m, int findAtKeys);

template <typename Key>
int easyfind(const std::map<Key,int> &m, int findAtVals);

int easyfind(const std::map<int,int> &m, int findAtKeys);

#include "easyfind.tpp"


#endif
