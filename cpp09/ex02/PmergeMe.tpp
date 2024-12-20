#include "utils.hpp"

template <class Container>
void fillContainer(Container&chain_A, Container&chain_B, char *av[]) {
	int first, second, i;
	for (i = 1; av[i] && av[i + 1]; i += 2) {
		first = my_stoi(av[i]);
		second = my_stoi(av[i+1]);
		if (second > first)
			std::swap(second, first);
		chain_A.push_back(first);
		chain_B.push_back(second);
	}
	if (av[i])
		chain_B.push_back(my_stoi(av[i]));
}

template <class Container>
void insertionSort(Container &dest, Container &src) {

    typename Container::iterator src_it = src.begin();
    typename Container::iterator src_end = src.end();

    while (src_it != src_end) {
        typename Container::iterator it = std::lower_bound(dest.begin(), dest.end(), *src_it);
        dest.insert(it, *src_it);
        ++src_it;
    }
}

template <typename T>
double measureTime(void (T::*fun)(void), T& obj) {
    clock_t start = clock();
    (obj.*fun)();
    clock_t end = clock();
    return (static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC);
}
