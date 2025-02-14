#include "Harl.hpp"


int main()
{
	Harl obj;
	std::string input;
    while (1) {
		std::cout<<"Type the action: "<<std::endl;
		std::getline(std::cin, input);
		obj.complain(input);
	}
	return (0);
}
