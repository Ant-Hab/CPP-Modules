#pragma once

#include <iostream>
#include <string>

class Brain {
    public:
        std::string ideas[100];

        Brain();
        Brain(const Brain& src);
        Brain& operator=(const Brain& rhs);
        ~Brain();
};
