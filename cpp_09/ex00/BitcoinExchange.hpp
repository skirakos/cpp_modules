#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, double> data;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& original);
        BitcoinExchange& operator=(const BitcoinExchange& original);
       // ~BitcoinExchange();

        std::map<std::string, double> getData() ;
        static std::string* split(std::string) ;

};


#endif