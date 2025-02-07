#include "PhoneBook.hpp"


PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::addContact()
{
	if (index < 8)
	{
		contacts[index].setContactDetails(index);
		index++;
	}
	else
	{
		for (int i = 1; i < 8; ++i){
			contacts[i - 1] = contacts[i];
			contacts[i - 1].setIndex(i - 1);
		}
		contacts[7].setContactDetails(index - 1);
	}
	
	std::cout<<"Contact added successfully!" << std::endl;
}

void	PhoneBook::displayAllContacts()
{
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < index; i++) {
		contacts[i].displayFourColumn();
	}
}

void	PhoneBook::searchContact()
{
	int	input_index;

	displayAllContacts();
	std::cout << "Enter the contact index: ";
	std::cin >> input_index;
	std::cin.ignore();
	if (input_index >= 0 && input_index <= index)
		contacts[input_index].displayAllColumns();
	else
		std::cout<<"Invalid index.\n";
}


