#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
		T* arr;
		size_t len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& original);
		Array& operator=(const Array& original);
		T&	operator[](size_t index);
		const T& operator[](size_t index) const;
		size_t size();

		~Array();
};
#include "Array.tpp"
#endif