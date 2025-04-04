#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
	private:
		std::vector<int> vec;
		unsigned int n;
	public:
		Span();
		Span(unsigned int num);
		Span(const Span& original);
		Span& operator=(const Span& original);
		void addNumber(int value);
		template <typename T>
		void addNumbers(T begin, T end);
		int	shortestSpan();
		int	longestSpan();
		~Span();
};
template <typename T>
void Span::addNumbers(T begin, T end) {

    while (begin != end)
    {
        addNumber(*begin);
		begin++;
    }
}
#endif