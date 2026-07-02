#include "Cat.hpp"

/*
** Default Constructor: Sets type to Cat.
*/
Cat::Cat() {
    std::cout << "Cat default constructor called\n";
    this->type = "Cat";
}

/*
** Copy Constructor: Copies the state from another Cat object.
*/
Cat::Cat(const Cat& src) : Animal(src) {
    std::cout << "Cat copy constructor called\n";
}

/*
** Assignment Operator: Safely handles copying data between already existing objects.
*/
Cat& Cat::operator=(const Cat& rhs) {
    std::cout << "Cat assignment operator called\n";
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

/*
** Destructor: Cleans up the Cat object.
*/
Cat::~Cat() {
    std::cout << "Cat destructor called\n";
}

/*
** makeSound implementation: Outputs the specific sound of the cat.
*/
void Cat::makeSound() const {
    std::cout << "Meow! Meow!\n";
}
