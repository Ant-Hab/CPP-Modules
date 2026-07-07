#pragma once

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& type, int val) {
    typename T::iterator it = std::find(type.begin(), type.end(), val);
    if (it == type.end())
        throw std::out_of_range("Value not found");
    else
        return it;
}