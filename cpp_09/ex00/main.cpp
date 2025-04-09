#include "BitcoinExchange.hpp"

void	exchange(std::string date, double value) {
	if (value < 0) {
		std::cout << "Error: not a positive number.\n";
		return ;
	}

	BitcoinExchange obj;
	std::map<std::string, double> db = obj.getData();
	std::map<std::string, double>::iterator lb = db.lower_bound(date);
	if (lb != db.end()) {
		if (lb->first == date){
			std::cout <<date<< " => "<<value<<" = " << lb->second*value << '\n';
		}
		else {
			if(lb != db.begin())
				lb--;
			std::cout << date << " => "<<value<<" = " << lb->second*value  << '\n';
		}
	} else {
		lb--;
		std::cout << date << " => "<<value<<" = " << lb->second*value  << '\n';
	}
}

bool isValid(std::string& line, std::string& key, double value) {
	if (key.length() != 10) {
		std::cout<<"Invalid date format: must be YYYY-MM-DD. "<<std::endl;
		return (false);
	}
	for (size_t i = 0; i < key.length(); i++)
	{
		if ((i == 4 || i == 7) && key[i] != '-') {
			std::cout<<"Invalid date format: must be YYYY-MM-DD. "<<std::endl;
			return (false);
		}
		if ((key[i] < '0' || key[i] > '9') && (i != 4 && i != 7)) {
			std::cout<<"2Invalid date format: must be YYYY-MM-DD. "<<std::endl;
			return (false);
		}
	}
	
	if (line.substr(13, line.find('\n') - 1) != "0.0" && value == 0.0) {
		std::cout<<"Error: bad input => "<<line<<std::endl;
		return (false);
	}
	else if (value > 1000) {
		std::cout<<"Error: too large a number."<<std::endl;
		return (false);
	}
	return (true);
}

void processData(std::fstream& file) {
	std::string line;
	double value;
	std::string key;
	std::getline(file, line);
	if (line != "date | value") {
		std::cout<<"Error: invalid input"<<std::endl;
		return ;
	}
	while (std::getline(file, line))
	{
		if (line.find(" | ") == std::string::npos) {
			std::cout << "Invalid input format" << std::endl;
			continue ;
		}
		if (line.length() < 14) {
			std::cout<<"Error: bad input => "<<line<<std::endl;
			continue;
		}

		char* end;
    	value = strtod(line.substr(13, line.find('\n') - 1).c_str(), &end);
    	if (*end != '\0') {
        	std::cout << "Error: invalid input of the value: " << end << std::endl;
			continue ;
		}

		value = std::atof(line.substr(13, line.find('\n') - 1).c_str());
		key = line.substr(0, 10);
		if (!isValid(line, key, value))
			continue;
		exchange(key, value);
	}
}

int main(int argc, char **argv) {
    if (argc == 1) {
		std::cout<<"Error: could not open file.\n";
		return (1);
	}
	if (argc == 2) {
		std::fstream file(argv[1]);
		if (!file) {
			std::cout<<"Error: could not open file.\n";
			return (1);
		}
		else {
			processData(file);
		}
	}
    return 0;
}