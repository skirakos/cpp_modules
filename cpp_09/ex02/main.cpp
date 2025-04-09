#include "PmergeMe.hpp"
#include <climits>
#include <cstring>
#include <cstdlib>

static bool checkOverflow(const char* str) {
	if (std::strlen(str) > 11)
		return true;
	long nbr = std::atol(str);
	return (nbr > INT_MAX || nbr < INT_MIN);
}

static void checkDigitsOnly(const std::string& arg) {
	for (size_t i = 0; i < arg.length(); ++i) {
		if (!std::isdigit(arg[i])) {
			std::cerr << "Error: invalid input\n";
			exit(1);
		}
	}
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: ./PmergeMe <positive integers...>" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];

		if (arg.find(' ') != std::string::npos) {
			std::cerr << "Error: input shouldn't contain spaces\n";
			return 1;
		}

		if (checkOverflow(argv[i])) {
			std::cerr << "Error: overflow " << arg << "\n";
			return 1;
		}

		checkDigitsOnly(arg);

		int num = std::atoi(argv[i]);
		if (num <= 0) {
			std::cerr << "Error: invalid input\n";
			return 1;
		}

		vec.push_back(num);
		deq.push_back(num);
	}

	std::cout << "Before: ";
	printContainer(vec);

	PmergeMe::sort(vec, deq);

	return 0;
}
