#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <limits.h>

ScalarConverter::ScalarConverter() {
    //std::cout<<"ScalarConverter constructor is called!\n";
}
ScalarConverter::ScalarConverter(const ScalarConverter&) {
    //std::cout<<"ScalarConverter copy constructor is called!\n";
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ) {
    // std::cout << "Copy assignment of ScalarConverter operator called\n";
    return *this;
}
void    print_char(double x) {
    if (x >= 0 && x <= 127) {
        if ((x >= 0 && x <= 32) || x == 127)
            std::cout<<"char: Non displayable\n";
        else
            std::cout<<"char: "<<static_cast<char>(x)<<"\n";
    }
    else 
        std::cout<<"char: impossible\n";
}

void    print_int(double x) {
    if (x > INT_MAX && x < INT_MIN) {
        std::cout<<"int: impossible\n";
    }
    else
        std::cout<<"int: "<<static_cast<int>(x)<<"\n";
}

void    print_float(double x) {
    if (x > std::numeric_limits<float>::max() && x < std::numeric_limits<float>::min()) {
        std::cout<<"float: impossible\n";
    }
    else {
        if (x > static_cast<int>(x))
            std::cout<<"float: "<<static_cast<float>(x)<<"f\n";
        else
            std::cout<<"float: "<<static_cast<float>(x)<<".0f\n";
    }
}

void    print_double(double x) {
    if (x == static_cast<int>(x))
        std::cout<<"double: "<<x<<".0\n";
    else
        std::cout<<"double: "<<x<<"\n";
}

void ScalarConverter::convert(std::string value) {
    if (value == "inf" || value == "+inf" || value == "inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << std::numeric_limits<float>::infinity() << "f\n";
        std::cout << "double: " << std::numeric_limits<double>::infinity() << "\n";
        return;
    }
    if (value == "-inf" || value == "-inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f\n";
        std::cout << "double: " << -std::numeric_limits<double>::infinity() << "\n";
        return;
    }
    if (value == "nan" || value == "nanf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return;
    }

    if (value.length() > 1 && value[value.length()  - 1] == 'f') {
        value.erase(value.length()  - 1);
        if (value == "."){
            std::cout<<"Error.\n";
            return ;
        }
        else if (std::isalpha(value[0])) {
            std::cout<<"Error.\n";
            return ;
        }
        if (value[value.length()  - 1] == '.')
            value.erase(value.length()  - 1);
        for (size_t i = 0; i<value.length(); i++) {
            if (!std::isdigit(value[i]) && value[i] != '.') {
                std::cout<<"Error3.\n";
                return ;
            }
        }
    }
    if (value.length() == 1 && isascii(value[0])) {
        print_char(value[0]);
        print_int(value[0]);
        print_float(value[0]);
        print_double(value[0]);
        return ;
    }
    std::stringstream ss(value);
    double x;
    if (!(ss >> x) || !ss.eof()) {
        std::cout << "Error: Invalid input for double conversion." << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;

    } else {
        print_char(x);
        print_int(x);
        print_float(x);
        print_double(x);
    }
}
ScalarConverter::~ScalarConverter() {
    std::cout<<"ScalarConverter decstructor is called!\n";
}


// inf     Positive Infinity (1.0 / 0.0)
// -inf    Negative Infinity (-1.0 / 0.0)
// nan     Not a Number (e.g., sqrt(-1))
// inff    Infinity (float type)
// -inff   Negative Infinity (float type)
