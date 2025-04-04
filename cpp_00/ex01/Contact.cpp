#include "Contact.hpp"

int	check_name(std::string name)
{
	int	i = 0;

	while(name[i])
	{
		if (isalpha(name[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_num(std::string number)
{
	int	i = 0;

	while(number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void Contact::setContactDetails(int index)
{
	do
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
	}
	while (check_name(first_name) == 0);

	do
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
	}
	while (check_name(last_name) == 0);
	
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);

	do
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone_number);
	}
	while (check_num(phone_number) == 0);
	
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);

	this->index = index;
}
void	Contact::setIndex(int k) {
	this->index = k;
}

std::string Contact::truncateField(const std::string& field) const { //can't change class atributes when the const is written
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void Contact::displayFourColumn()
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncateField(first_name) << "|";
	std::cout << std::setw(10) << truncateField(last_name) << "|";
	std::cout << std::setw(10) << truncateField(nickname) << std::endl;
}

void Contact::displayAllColumns()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}