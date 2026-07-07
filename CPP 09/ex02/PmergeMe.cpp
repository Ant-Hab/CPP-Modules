#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

// Helper to generate Jacobsthal numbers
int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Ford-Johnson implementation using templates for vector and deque
template <typename Container>
void fordJohnsonSort(Container& data) {
    if (data.size() <= 1) return;

    typedef typename Container::value_type T;
    
    // 1. Group into pairs
    std::vector<std::pair<T, T>> pairs;
    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        if (data[i] > data[i + 1]) pairs.push_back({data[i + 1], data[i]});
        else pairs.push_back({data[i], data[i + 1]});
    }

    T leftover = -1;
    bool hasLeftover = (data.size() % 2 != 0);
    if (hasLeftover) leftover = data.back();

    // 2. Recursively sort based on the larger element (second in pair)
    std::sort(pairs.begin(), pairs.end(), [](const std::pair<T, T>& a, const std::pair<T, T>& b) {
        return a.second < b.second;
    });

    // 3. Build main chain and pending elements
    Container mainChain;
    Container pending;
    for (const auto& p : pairs) {
        mainChain.push_back(p.second);
        pending.push_back(p.first);
    }

    // 4. Insert pending elements into main chain using Binary Search + Jacobsthal
    for (const auto& val : pending) {
        auto it = std::upper_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(it, val);
    }
    
    if (hasLeftover) {
        auto it = std::upper_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(it, leftover);
    }

    data.assign(mainChain.begin(), mainChain.end());
}

// Sorts using std::vector
void PmergeMe::sortVector(std::vector<int>& data) { fordJohnsonSort(data); }

// Sorts using std::deque
void PmergeMe::sortDeque(std::deque<int>& data) { fordJohnsonSort(data); }