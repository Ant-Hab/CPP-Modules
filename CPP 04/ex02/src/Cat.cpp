#include "Cat.hpp"

/* Cat implementation inheriting from abstract AAnimal */
Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat created" << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    this->brain = NULL;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->type = other.type;
        if (this->brain) delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }
Brain* Cat::getBrain() const { return this->brain; }