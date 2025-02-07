#pragma once
#include <iomanip>
#include <string>
#include <iostream>
#include "Contact.hpp"
#include <cctype>

class PhoneBook
{
	private:
		Contact contacts[8];
		int		index;

	public:
		PhoneBook();

		void addContact();

		void	displayAllContacts();

		void	searchContact();
};