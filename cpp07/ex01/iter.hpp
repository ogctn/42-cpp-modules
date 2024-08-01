#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void f1(T &elem) { elem += 3; }

template <typename T, int INC = 3>
struct s_fun{
	void operator()(T &elem) { elem += INC; }
};

template <template<typename> class Func, typename T>
void iter(T *ptr, int N, Func<T> fnc){
	for (int i = 0; i < N; i++)
		fnc(ptr[i]);
}

template <typename T>
void iter(T *ptr, int N, void (*fnc)(T &)){
	for (int i = 0; i < N; i++)
		fnc(ptr[i]);
}

template <typename T>
void iter(T &ref, int N, void (*fnc)(T &)){
	for (int i = 0; i < N; i++)
		fnc(ref);
}

template <typename T>
void iter(T *ptr, int N, void (*fnc)(T const &)){
	for (int i = 0; i < N; i++)
		fnc(ptr[i]);
}


template <template <typename,int> class Func, typename T, int INC>
void iter(T *ptr, int N, Func<T, INC> fnc){
	for (int i = 0; i < N; i++)
		fnc(ptr[i]);
}

// --------------------------------------------------------
void my_toupper(std::string &s) {
	for (size_t i = 0; i < s.length(); i++) {
		s[i] = std::toupper(s[i]);
	}
}

template <typename T>
void print_arr(T *arr, int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

#endif
