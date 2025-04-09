#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <algorithm>

class PmergeMe {
    private:
        PmergeMe();
        PmergeMe(const PmergeMe&);
        PmergeMe &operator=(const PmergeMe&);
        ~PmergeMe();
    public:
        static void sort(std::vector<int>& vec, std::deque<int>& deq);
};

bool isNumber(const std::string& s);
template<typename T> void printContainer(const T& container);

#endif
