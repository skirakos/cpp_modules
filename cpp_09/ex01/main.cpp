#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
		std::cout<<"Error: Invalid input format.\n";
		return (1);
	}
	RPN expression(argv[1]);
    return 0;
}