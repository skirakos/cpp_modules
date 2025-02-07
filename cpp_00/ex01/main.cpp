#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;

	std::string input;
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cout<< "Invalid command :)" << std::endl;
	}
	return 0;
}