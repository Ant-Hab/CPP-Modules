#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>

// Entry point: Initializes containers, performs the Ford-Johnson sort, and benchmarks results
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> v;
    std::deque<int> d;

    // Parsing inputs
    for (int i = 1; i < argc; ++i) {
        try {
            int val = std::stoi(argv[i]);
            if (val < 0) throw std::invalid_argument("negative");
            v.push_back(val);
            d.push_back(val);
        } catch (...) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); ++i) std::cout << v[i] << (i == v.size() - 1 ? "" : " ");
    std::cout << std::endl;

    PmergeMe pm;

    // Time Vector
    auto startV = std::chrono::high_resolution_clock::now();
    pm.sortVector(v);
    auto endV = std::chrono::high_resolution_clock::now();

    // Time Deque
    auto startD = std::chrono::high_resolution_clock::now();
    pm.sortDeque(d);
    auto endD = std::chrono::high_resolution_clock::now();

    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); ++i) std::cout << v[i] << (i == v.size() - 1 ? "" : " ");
    std::cout << std::endl;

    // Print output (Before/After/Time)
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " 
              << std::chrono::duration<double, std::micro>(endV - startV).count() << " us" << std::endl;
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " 
              << std::chrono::duration<double, std::micro>(endD - startD).count() << " us" << std::endl;

    return 0;
}