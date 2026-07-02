#include "Animal.hpp"

/*
** Default Constructor: Initializes the base Animal object.
*/
Animal::Animal() {
    std::cout << "Animal default constructor called\n";
}

/*
** Copy Constructor: Copies the type attribute from the source Animal.
*/
Animal::Animal(const Animal& src) : type(src.type) {
    std::cout << "Animal copy constructor called\n";
}

/*
** Assignment Operator: Safely handles copying the type attribute between existing Animal objects.
*/
Animal& Animal::operator=(const Animal& rhs) {
    std::cout << "Animal assignment operator called\n";
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

/*
** Destructor: Virtual destructor to ensure proper cleanup of derived objects.
*/
Animal::~Animal() {
    std::cout << "Animal destructor called\n";
}

/*
** getType implementation: Returns the type string of the animal.
*/
std::string Animal::getType() const {
    return this->type;
}

/*
** makeSound implementation: Outputs the generic sound of the animal.
*/
void Animal::makeSound() const {
    std::cout << "Generic sound\n";
}
