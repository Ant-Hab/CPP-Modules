#include "Dog.hpp"

/*
** Default Constructor: Sets type to Dog.
*/
Dog::Dog() {
    std::cout << "Dog default constructor called\n";
    this->type = "Dog";
}

/*
** Copy Constructor: Copies the state from another Dog object.
*/
Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog copy constructor called\n";
}

/*
** Assignment Operator: Safely handles copying data between already existing objects.
*/
Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog assignment operator called\n";
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

/*
** Destructor: Cleans up the Dog object.
*/
Dog::~Dog() {
    std::cout << "Dog destructor called\n";
}

/*
** makeSound implementation: Outputs the specific sound of the dog.
*/
void Dog::makeSound() const {
    std::cout << "Woof! Woof!\n";
}
