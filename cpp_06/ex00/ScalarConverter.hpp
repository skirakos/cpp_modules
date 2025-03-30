#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>


class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(std::string newName, int newGradeS, int newGradeE);
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
    public:
        static void convert(std::string value); //why static? because it is more like a utilitiy class, that can be used without creating new object
};

std::ostream& operator<<(std::ostream& os, const ScalarConverter& obj);

#endif