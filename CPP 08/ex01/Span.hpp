#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

class Span {
private:
    std::vector<int> _span;
    unsigned int     _N;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void         insertNumbers(const std::vector<int>& numbers);
    void         addNumber(int num);
    unsigned int shortestSpan();
    unsigned int longestSpan();
};