#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange () {
    std::fstream file("data.csv");
    if (!file) {
        std::cout<<"Error: could not open file.\n";
        return ;
    }
    else {
        std::string line;
        std::string key;
        std::string value;
        std::getline(file, line);
        if (line != "date,exchange_rate") {
            std::cout<<"Error DB: invalid input"<<std::endl;
            return ;
        }
        while (std::getline(file, line))
        {
            key = line.substr(0, 10);
            value = line.substr(11, line.find('\n') - 1);
            data.insert(std::make_pair(key, std::atof(value.c_str())));
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& original) {
    this->data = original.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& original) {
    if (this != &original) {
        this->data = original.data;
    }
    return *this;
}

std::map<std::string, double> BitcoinExchange::getData() {
    return data;
}

BitcoinExchange::~BitcoinExchange () {}