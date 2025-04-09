#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
		std::cout<<"Error: could not open file.\n";
		return (1);
	}
	if (argc == 2) {
		RPN expression(argv[1]);

	}
    return 0;
}