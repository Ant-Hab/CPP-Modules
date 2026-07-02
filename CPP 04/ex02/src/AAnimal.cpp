#include "AAnimal.hpp"

/*
** Default Constructor: Initializes the base AAnimal object.
*/
AAnimal::AAnimal() {
    std::cout << "AAnimal default constructor called\n";
}

/*
** Copy Constructor: Copies the type attribute from the source AAnimal.
*/
AAnimal::AAnimal(const AAnimal& src) : type(src.type) {
    std::cout << "AAnimal copy constructor called\n";
}

/*
** Assignment Operator: Safely handles copying the type attribute between existing AAnimal objects.
*/
AAnimal& AAnimal::operator=(const AAnimal& rhs) {
    std::cout << "AAnimal assignment operator called\n";
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

/*
** Destructor: Virtual destructor to ensure proper cleanup of derived objects.
*/
AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called\n";
}

/*
** getType implementation: Returns the type string of the animal.
*/
std::string AAnimal::getType() const {
    return this->type;
}
