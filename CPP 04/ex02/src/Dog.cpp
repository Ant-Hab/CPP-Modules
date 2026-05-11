#include "Dog.hpp"

/* Dog implementation inheriting from abstract AAnimal */
Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog created" << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    this->brain = NULL;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->type = other.type;
        if (this->brain) delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
Brain* Dog::getBrain() const { return this->brain; }