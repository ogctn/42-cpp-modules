#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, int INC = 3>
struct s_fun{
	void operator()(T &elem) { elem += INC; }
};

template <template<typename> class Func, typename T>
void iter(T *ptr, int N, Func<T> fnc){
	if (N <= 0 || !fnc || !ptr)
		return ;
	for (int i = 0; i < N; i++)
		fnc(ptr[i]);
}

template <typename T>
void iter(T *ptr, int N, void (*fnc)(T &)){
	if (N <= 0 || !fnc || !ptr)
		return ;
	for (int i = 0; i < N; i++)
		fnc(ptr[i]);
}

template <typename T>
void iter(T &ref, int N, void (*fnc)(T &)){
	if (N <= 0 || !*fnc)
		return ;
	for (int i = 0; i < N; i++)
		fnc(ref);
}

template <typename T>
void iter(T *ptr, int N, void (*fnc)(T const &)){
	if (N <= 0 || !fnc || !ptr)
		return ;
	for (int i = 0; i < N; i++)
		fnc(ptr[i]);
}

template <template <typename,int> class Func, typename T, int INC>
void iter(T *ptr, int N, Func<T, INC> fnc){
	if (N <= 0 || !ptr)
		return ;
	for (int i = 0; i < N; i++)
		fnc(ptr[i]);
}

/* ----------------------------------------- */
void my_toupper(std::string &s) {
	for (size_t i = 0; i < s.length(); i++) {
		s[i] = std::toupper(s[i]);
	}
}

void stringLower(std::string &s) {
	for (size_t i = 0; i < s.length(); i++)
		s[i] = std::tolower(s[i]);
}

template <typename T>
void print_arr(T *arr, int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
/* ----------------------------------------- */

#endif
