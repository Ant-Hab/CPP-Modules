#include "Cat.hpp"

/*
** Default Constructor: Sets type to Cat and allocates a new Brain.
*/
Cat::Cat() {
    std::cout << "Cat default constructor called\n";
    this->type = "Cat";
    this->brain = new Brain();
}

/*
** Copy Constructor: Allocates a completely NEW brain and copies the contents (Deep Copy).
*/
Cat::Cat(const Cat& src) : AAnimal(src) {
    std::cout << "Cat copy constructor called\n";
    this->brain = new Brain(*src.brain);
}

/*
** Assignment Operator: Prevents memory leaks by freeing the old brain and allocating a new one with copied data.
*/
Cat& Cat::operator=(const Cat& rhs) {
    std::cout << "Cat assignment operator called\n";
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
Cat::~Cat() {
    std::cout << "Cat destructor called\n";
    delete this->brain;
}

/*
** makeSound implementation: Outputs the specific sound of the cat.
*/
void Cat::makeSound() const {
    std::cout << "Meow! Meow!\n";
}
