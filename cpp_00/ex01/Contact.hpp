#pragma once
#include <iomanip>
#include <string>
#include <iostream>
#include <cctype>

class Contact
{
	private:
		int index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void setContactDetails(int index);

		void	setIndex(int k);

		std::string truncateField(const std::string& field) const;

		void displayFourColumn();

		void displayAllColumns();
};