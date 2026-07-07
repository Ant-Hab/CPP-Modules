#include "Span.hpp"

int main() {
    try {
        int num = 10000;
        Span sp = Span(num + 1);
        sp.addNumber(-10);
        Span sp2(sp);
        
        for (int i = 0; i < num; i++) {
            sp.addNumber(i);
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
        std::vector<int> v = {100, 1000, 1};
        sp2.insertNumbers(v);
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}