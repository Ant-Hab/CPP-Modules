#include "Weapon.hpp"

/* Initializes weapon with a specific type string */
Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

/* Returns a constant reference to the type to avoid unnecessary string copying */
const std::string& Weapon::getType() const 
{
    return this->_type;
}

/* Updates the weapon type string */
void Weapon::setType(std::string type) 
{
    this->_type = type;
}