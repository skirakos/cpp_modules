#include <string.h>
#include <iostream>
#include <stdio.h>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout<< &str <<std::endl;
	std::cout<< stringPTR <<std::endl;
	std::cout<< &stringREF <<std::endl;

	std::cout<< str <<std::endl;
	std::cout<< *stringPTR <<std::endl;
	std::cout<< stringREF <<std::endl;
	return(0);
}

// when we have *str, printing str will print the address, *str the will print the value
// when we have string str, &str will print the adress of str