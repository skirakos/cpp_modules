#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) {return (*this);}
PmergeMe::~PmergeMe() {}
bool isNumber(const std::string& s) {
	for (size_t i = 0; i < s.length(); ++i) {
		if (!isdigit(s[i]))
			return false;
	}
	return !s.empty();
}

template <typename Container>
void	insert(Container &left, Container &right) {
	size_t n = 0;
	size_t power = 0;
	size_t start = 0;
	size_t end = 0;

	for (size_t i = 0; i < right.size();)
	{
		++power;

		n = std::pow(2, power) - n;

		start += n;

		end = start - n;

		if (start > right.size())
			start = right.size();

		for (size_t j = start - 1; j >= end;)
		{
			left.insert(std::upper_bound(left.begin(), left.end(), right[j]), right[j]);
			++i;
			if (j == 0)
				break ;
			--j;
		}
	}
}

template<typename T>
void fordJohnsonSort(T& container) {
	T larger;
	T smaller;

	if (container.size() < 2)
		return ;
	for (size_t i = 0; i < container.size(); i += 2) {
		if (i + 1 < container.size()) {
			if (container[i] > container[i + 1]) {
				larger.push_back(container[i]);
				smaller.push_back(container[i + 1]);
			} else {
				larger.push_back(container[i + 1]);
				smaller.push_back(container[i]);
			}
		} else {
			smaller.push_back(container[i]);
		}
	}
	fordJohnsonSort(larger);
	insert(larger, smaller);
	container = larger;
}

void PmergeMe::sort(std::vector<int>& vec, std::deque<int>& deq) {
	std::clock_t start, end;

	start = std::clock();
	fordJohnsonSort(vec);
	end = std::clock();
	double timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	start = std::clock();
	fordJohnsonSort(deq);
	end = std::clock();
	double timeDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	
	std::cout << "After: ";
	printContainer(vec);

	std::cout << "Time to process a range of " << vec.size()
	          << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec * 1000000 << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
	          << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq  * 1000000<< " us" << std::endl;
}

template void printContainer(const std::vector<int>& container);
template void printContainer(const std::deque<int>& container);

template<typename T>
void printContainer(const T& container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
