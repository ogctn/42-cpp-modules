template <class T>
void	print(const T &toPrint) {
	
	typename T::const_iterator it = toPrint.begin();

	while (it != toPrint.end())
	{
		std::cout << (it)->first << " ";
		if ((it)->second != -1)
			std::cout << (it)->second << " ";
		++it;
	}
	std::cout << std::endl;
}

// all the code below is in the PmergeMe.tpp file must be corresponded to C98 standard
// no lambda, no auto, no range-based for loop, no nullptr, no template alias, no template template, no variadic template
// no std::function, no std::bind, no std::forward, no std::move, no std::unique_ptr, no std::shared_ptr, no std::weak_ptr
// no std::array, no std::unordered_map, no std::unordered_set, no std::tuple, no std::make_tuple, no std::tie
// no std::get, no std::apply, no std::invoke, no std::to_string, no std::stoi, no std::stod, no std::stof, no std::stol
// etc.

template <class T>
void	sortLeftOfPairs(T &toSort) {
	typename T::iterator it1 = toSort.begin();
	typename T::iterator ite = toSort.end();
	typename T::iterator it2;
	std::pair<int, int> tmp;

	while (it1 != ite) {
		it2 = it1;
		while (++it2 != ite) {
			if ((it1->first > it2->first) ||
			(it1->first == it2->first && it1->second > it2->second)) {
				tmp = *it1;
				*it1 = *it2;
				*it2 = tmp;
			}
		}
		++it1;
	}
}

template <class T>
void	FJA(T &toSort) {
	sortLeftOfPairs(toSort);
	
	// Complete the algo
	// ...
	

}

