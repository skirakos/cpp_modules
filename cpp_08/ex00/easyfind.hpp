#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <list>

template <typename T> int easyfind(T a, int b) {
	typename T::iterator it = a.begin(); //why typename is written
	int i = 0;
	while (it != a.end())
	{
		if (*it == b)
			return(i);
		it++;
		i++;
	}
	
	return (-1);
}

#endif