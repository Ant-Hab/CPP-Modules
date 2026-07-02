#include "WrongCat.hpp"

/*
** Default Constructor: Sets type to WrongCat.
*/
WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called\n";
    this->type = "WrongCat";
}

/*
** Copy Constructor: Copies the state from another WrongCat object.
*/
WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
    std::cout << "WrongCat copy constructor called\n";
}

/*
** Assignment Operator: Safely handles copying data between already existing objects.
*/
WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    std::cout << "WrongCat assignment operator called\n";
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

/*
** Destructor: Cleans up the WrongCat object.
*/
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called\n";
}

/*
** makeSound implementation: Outputs the specific sound of the wrong cat.
*/
void WrongCat::makeSound() const {
    std::cout << "Wrong Meow! Wrong Meow!\n";
}
