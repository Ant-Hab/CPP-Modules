#include "Animal.hpp"

/* Animal implementation */
Animal::Animal() : type("Animal") { std::cout << "Animal created" << std::endl; }
Animal::~Animal() { std::cout << "Animal destroyed" << std::endl; }
Animal::Animal(const Animal& other) { *this = other; }
Animal& Animal::operator=(const Animal& other) {
    if (this != &other) this->type = other.type;
    return *this;
}
void Animal::makeSound() const { std::cout << "Generic sound" << std::endl; }
std::string Animal::getType() const { return this->type; }