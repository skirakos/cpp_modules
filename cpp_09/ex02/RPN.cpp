#include "RPN.hpp"

RPN::RPN () {}

RPN::RPN(const RPN& original) {
    this->expression = original.expression;
    this->nums = original.nums;
}

RPN& RPN::operator=(const RPN& original) {
    if (this != &original) {
        this->expression = original.expression;
        this->nums = original.nums;
    }
    return *this;
}

bool RPN::isValid() {
    size_t pos_1 = expression.find(')');
    size_t pos_2 = expression.find('(');
    if (pos_1 != std::string::npos || pos_2 != std::string::npos) {
        std::cout << "Error: forbidden character\n";
        return (false);
    } else {
        return (true);
    }
}

int calculate(int a, int b, char op) {
    if (op == '+')
        return (a + b);
    else if (op == '-')
        return (a - b);
    else if (op == '*')
        return (a * b);
    else if (op == '/') {
        if (b == 0)
            return (-1);
        return (a / b);
    }
    return (-1);
}

RPN::RPN (std::string exp) {
    this->expression = exp;
    if (!isValid()) {
        return ;
    }
    for (size_t i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ') {
            continue;
        }
        if (i == 0 || i == 2) {
            if (expression[i] < '0' || expression[i] > '9') {
                std::cout << "Error: invalid input.\n";
                return ;
            }
        }
        if (expression[i] >= '0' && expression[i] <= '9') {
            int num = expression[i] - '0';
            this->nums.push(num);
        }
        else {
            if (nums.size() < 2) {
                std::cout << "Error: not enough operands for operation '" << expression[i] << "'\n";
                return;
            }
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            int result = calculate(a, b, expression[i]);
            if (result != -1) {
                nums.push(result);
            }
        }
    }
    if (nums.size() == 1) {
        std::cout << "Result: " << nums.top() << std::endl;
    } else {
        std::cout << "Error: invalid expression\n";
    }
}

RPN::~RPN () {}