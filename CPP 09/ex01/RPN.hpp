#pragma once

#include <string>
#include <stack>

class RPN {
private:
    std::stack<long> _stack;

    // Performs math operation on the top two elements
    void performOperation(char op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    // Parses and calculates the RPN expression
    void calculate(const std::string& expression);
};