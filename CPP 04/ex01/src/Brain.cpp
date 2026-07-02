#include "Brain.hpp"

/*
** Default Constructor: Initializes an empty Brain object.
*/
Brain::Brain() {
    std::cout << "Brain default constructor called\n";
}

/*
** Copy Constructor: Iterates through the ideas array to perform a deep copy.
*/
Brain::Brain(const Brain& src) {
    std::cout << "Brain copy constructor called\n";
    *this = src;
}

/*
** Assignment Operator: Safely overwrites the current ideas array with the contents of the source Brain.
*/
Brain& Brain::operator=(const Brain& rhs) {
    std::cout << "Brain assignment operator called\n";
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

/*
** Destructor: Destroys the Brain object.
*/
Brain::~Brain() {
    std::cout << "Brain destructor called\n";
}
