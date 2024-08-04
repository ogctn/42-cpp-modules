#include "easyfind.hpp"
#include <iostream>
#include <cstdlib>	//srand()
#include <time.h>	//time()

#include <vector>
#include <deque>
#include <list>
#include <map>


template < typename Cont >
void print(const Cont &c) {
	typename Cont::const_iterator it;
	std::cout << "[";
	for (it = c.begin(); it != c.end(); )
		std::cout <<  *it << ((++it) != c.end() ? ", ":"");
	std::cout << " ]" << std::endl;
}

template < typename Cont >
void print(const Cont &c, int s) {
	typename Cont::const_iterator it;
	std::cout << "[";
	for (it = (c.begin() + s); it != c.end(); )
		std::cout << *it << ((++it) != c.end() ? ", ":"");
	std::cout << " ]" << std::endl;
}

template <typename A, typename B>
void print(const std::map<A,B> &m)
{
	typename std::map<A,B>::const_iterator it;
	std::cout << "[";
	for (it = m.begin(); it != m.end(); )
		std::cout << (*it).first
			<< ":" << (*it).second << ((++it) != m.end() ? ", ":"");
	std::cout << "]" << std::endl;
}

int	main() {
	std::vector<int>	v1;
	std::deque<int>		d1;
	std::list<int>		l1;
	std::map<int,int>	m1;
	std::map<std::string,int>	m2;
	std::map<int,std::string>	m3;

	srand(time(NULL));
	int max = 101;
	for (int i = 0; i < 10; i++) v1.push_back(rand() % max); v1.insert(v1.end(), 15);
	for (int i = 0; i < 10; i++) d1.push_back(rand() % max); d1.insert(d1.end(), 15);
	for (int i = 0; i < 10; i++) l1.push_back(rand() % max); l1.insert(l1.end(), 15);
	for (int i = 0; i < 10; i++) m1.insert(std::pair<int,int>(rand() % max, rand() % max));
	for (int i = 0; i < 10; i++) m2.insert(std::pair<std::string,int>(std::to_string(64 + (rand() % 58)), rand() % max));
	for (int i = 0; i < 10; i++) m3.insert(std::pair<int,std::string>(rand() % max, std::to_string(64 + (rand() % 58))));

	std::cout << "####  Search 15  ####" << std::endl;
	m1.insert(std::pair<int,int>(77,15));	// searches on values when map<int,int> provided 
	m2.insert(std::pair<std::string,int>("ogcetin",15));
	m3.insert(std::pair<int,std::string>(15,"ogcetin"));

	std::cout << "m1<int,int>: "; print(m1);
	std::cout << (easyfind(m1, 15) ? 
		"No matching element." : "Element found.") << std::endl;
		
	std::cout << "m2<string,int>: "; print(m2);
	std::cout << (easyfind(std::map<std::string,int>(m2), 15) ? 
		"No matching element." : "Element found.") << std::endl;

	std::cout << "m3<int,string>: "; print(m3);
	std::cout << (easyfind(m3, 15) ? 
		"No matching element." : "Element found.") << std::endl;
	std::cout << "__________________________\n" << std::endl;

	std::cout << "vector:\t"; print(v1);
	std::cout << "deque:\t"; print(d1);
	std::cout << "list:\t"; print(l1);
	std::cout << "map:\t"; print(m1);

	int to_find = rand() % max;
	std::cout << "\n------- Test for: " << to_find << " -------" << std::endl;
	
	std::cout << "vector:\t";
	std::cout << (easyfind(v1, to_find) ? 
			"No matching element." : "Element found.") << std::endl;

	std::cout << "deque:\t";
	std::cout << (easyfind(d1, to_find) ? 
			"No matching element." : "Element found.") << std::endl;

	std::cout << "list:\t";
	std::cout << (easyfind(l1, to_find) ? 
			"No matching element." : "Element found.") << std::endl;

	std::cout << "map:\t";
	std::cout << (easyfind(m1, to_find) ? 
			"No matching element." : "Element found.") << std::endl;

}

