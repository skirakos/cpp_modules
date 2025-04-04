#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename A> void func(A& x) {
	std::cout<<x<<std::endl;
}
template <typename A> void iter(A* array, int len, void (*func)(A&)) {
	for (int i = 0; i < len; i++) {
		func(array[i]);
	}
}

#endif