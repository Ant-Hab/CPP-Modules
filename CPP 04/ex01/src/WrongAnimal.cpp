#include "WrongAnimal.hpp"

/* WrongAnimal implementation for polymorphism counter-example */
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}