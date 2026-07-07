#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>

class PmergeMe {
private:
    // Helper to generate Jacobsthal numbers
    static int jacobsthal(int n);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // Sorts using std::vector
    static void sortVector(std::vector<int>& data);
    // Sorts using std::deque
    static void sortDeque(std::deque<int>& data);
};