#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void func(T &elem) {
	elem += 3;
}

template <typename T>
void iter(T *ptr, size_t N, (*f)(T)){
	for (size_t i = 0; i < N; i++)
		f(ptr[i]);
}

#endif
