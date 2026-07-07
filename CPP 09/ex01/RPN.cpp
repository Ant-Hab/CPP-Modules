#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(const RPN& other) : _stack(other._stack) {}
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) _stack = other._stack;
    return *this;
}
RPN::~RPN() {}

// Pops two values, applies operation, and pushes result back to stack
void RPN::performOperation(char op) {
    if (_stack.size() < 2) throw std::runtime_error("Error");
    long val2 = _stack.top(); _stack.pop();
    long val1 = _stack.top(); _stack.pop();
    
    switch (op) {
        case '+': _stack.push(val1 + val2); break;
        case '-': _stack.push(val1 - val2); break;
        case '*': _stack.push(val1 * val2); break;
        case '/': 
            if (val2 == 0) throw std::runtime_error("Error");
            _stack.push(val1 / val2); break;
    }
}

// Tokenizes the expression and manages stack flow
void RPN::calculate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;
    while (ss >> token) {
        if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
            performOperation(token[0]);
        } else if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            _stack.push(std::stol(token));
        } else {
            throw std::runtime_error("Error");
        }
    }
    if (_stack.size() != 1) throw std::runtime_error("Error");
    std::cout << _stack.top() << std::endl;
}