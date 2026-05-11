#include "WrongCat.hpp"

/* WrongCat implementation for polymorphism counter-example */
WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow" << std::endl;
}