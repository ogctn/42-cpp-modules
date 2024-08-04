#include "easyfind.hpp"

template <typename T>
int easyfind(const T &c, int to_find) {
	typename T::const_iterator it = std::find(c.begin(), c.end(), to_find);
	if (it != c.end())
		return (0);
	return (1);
}

template <typename Value>
int easyfind(const std::map<int,Value> &m, int findAtKeys) {
	typename std::map<int,Value>::const_iterator it = m.find(findAtKeys);
	if (it != m.end())
		return (0);
	return (1);
}

template <typename Key>
int easyfind(const std::map<Key,int> &m, int findAtVals) {
	typename std::map<Key,int>::const_iterator it;
	for (it = m.begin(); it != m.end(); it++)
		if (it->second == findAtVals)
			return (0);
	return (1);
}

int easyfind(const std::map<int,int> &m, int findAtVals) {
	 std::map<int,int>::const_iterator it;
	for (it = m.begin(); it != m.end(); it++)
		if (it->second == findAtVals)
			return (0);
	return (1);
}
