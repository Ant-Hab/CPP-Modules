#include "WrongAnimal.hpp"

/*
** Default Constructor: Initializes the base WrongAnimal object.
*/
WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor called\n";
}

/*
** Copy Constructor: Copies the type attribute from the source WrongAnimal.
*/
WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type) {
    std::cout << "WrongAnimal copy constructor called\n";
}

/*
** Assignment Operator: Safely handles copying the type attribute between existing objects.
*/
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    std::cout << "WrongAnimal assignment operator called\n";
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

/*
** Destructor: Non-virtual destructor demonstrating early binding issues.
*/
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called\n";
}

/*
** getType implementation: Returns the type string of the wrong animal.
*/
std::string WrongAnimal::getType() const {
    return this->type;
}

/*
** makeSound implementation: Outputs the generic sound of the wrong animal.
*/
void WrongAnimal::makeSound() const {
    std::cout << "Wrong generic sound\n";
}
