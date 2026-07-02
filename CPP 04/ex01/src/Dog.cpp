#include "Dog.hpp"

/*
** Default Constructor: Sets type to Dog and allocates a new Brain.
*/
Dog::Dog() {
    std::cout << "Dog default constructor called\n";
    this->type = "Dog";
    this->brain = new Brain();
}

/*
** Copy Constructor: Allocates a completely NEW brain and copies the contents (Deep Copy).
*/
Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog copy constructor called\n";
    this->brain = new Brain(*src.brain);
}

/*
** Assignment Operator: Prevents memory leaks by freeing the old brain and allocating a new one with copied data.
*/
Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog assignment operator called\n";
    if (this != &rhs) {
        this->type = rhs.type;
        delete this->brain;
        this->brain = new Brain(*rhs.brain);
    }
    return *this;
}

/*
** Destructor: Frees the dynamically allocated Brain to prevent memory leaks.
*/
Dog::~Dog() {
    std::cout << "Dog destructor called\n";
    delete this->brain;
}

/*
** makeSound implementation: Outputs the specific sound of the dog.
*/
void Dog::makeSound() const {
    std::cout << "Woof! Woof!\n";
}
