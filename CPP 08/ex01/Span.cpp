#include "Span.hpp"
/*
** Default Constructor: Initializes an empty Span.
*/
Span::Span() : _N(0) {}

/*
** Parameterized Constructor: Sets the maximum size N.
*/
Span::Span(unsigned int N) : _N(N) {}

/*
** Copy Constructor: Copies the Span container and size.
*/
Span::Span(const Span& other) : _span(other._span), _N(other._N) {}

/*
** Assignment Operator: Copies the Span data and size.
*/
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _span = other._span;
        _N = other._N;
    }
    return *this;
}

/*
** Destructor: Cleans up the Span object.
*/
Span::~Span() {}

/*
** insertNumbers: Adds a vector of numbers to the Span.
*/
void Span::insertNumbers(const std::vector<int>& numbers) {
    if ((_span.size() + numbers.size()) > _N)
        throw std::out_of_range("not enough space");
    _span.insert(_span.end(), numbers.begin(), numbers.end());
}

/*
** addNumber: Adds a single integer to the Span.
*/
void Span::addNumber(int num) {
    if (_span.size() < _N)
        _span.push_back(num);
    else
        throw std::out_of_range("not enough space");
}

/*
** shortestSpan: Finds the shortest distance between stored elements.
*/
unsigned int Span::shortestSpan() {
    if (_span.empty() || _span.size() == 1)
        throw std::out_of_range("not enough members");
    
    std::vector<int> sorted = _span;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int shortest = std::numeric_limits<unsigned int>::max();
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        unsigned int dif = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
        if (dif < shortest)
            shortest = dif;
    }
    return shortest;
}

/*
** longestSpan: Finds the longest distance between stored elements.
*/
unsigned int Span::longestSpan() {
    if (_span.empty() || _span.size() == 1)
        throw std::out_of_range("not enough members");
    
    auto minmax = std::minmax_element(_span.begin(), _span.end());
    return static_cast<unsigned int>(*minmax.second - *minmax.first);
}