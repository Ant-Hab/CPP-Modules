#include "AAnimal.hpp"

/* AAnimal class implementation (Note: makeSound has no body as it is pure virtual) */
AAnimal::AAnimal() : type("AAnimal") { std::cout << "AAnimal created" << std::endl; }
AAnimal::~AAnimal() { std::cout << "AAnimal destroyed" << std::endl; }
AAnimal::AAnimal(const AAnimal& other) { *this = other; }
AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) this->type = other.type;
    return *this;
}
std::string AAnimal::getType() const { return this->type; }