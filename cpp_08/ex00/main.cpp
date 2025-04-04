#include "easyfind.hpp"

int main( void ) {
	std::list<int> lst;
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(7);
	std::cout<<easyfind(lst, 6)<<std::endl;

	std::list<int> lst_2;
	std::cout<<easyfind(lst_2, -8)<<std::endl;

	return 0;
}