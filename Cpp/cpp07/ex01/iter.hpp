#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <limits.h>
#include <stdlib.h>

template<typename T>
void iter(T * tab, size_t const size, void(*f)(T const & a)){
	for (size_t i = 0;i<size;i++)
		f(tab[i]);
}

#endif
