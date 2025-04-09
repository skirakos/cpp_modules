#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
    private:
        std::string expression;
        std::stack<int> nums;
    public:
        RPN();
        RPN(std::string expression);
        RPN(const RPN& original);
        RPN& operator=(const RPN& original);
        ~RPN();

        bool isValid();

};


#endif