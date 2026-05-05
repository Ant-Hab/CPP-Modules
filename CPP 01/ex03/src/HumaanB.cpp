#include "HumanB.hpp"

/* HumanB starts with no weapon (NULL pointer) */
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

/* Assigns a weapon address to the pointer */
void HumanB::setWeapon(Weapon& weapon) 
{
    this->_weapon = &weapon;
}

/* Attacks only if the weapon pointer is not NULL to avoid segfaults */
void HumanB::attack() const 
{
    if (this->_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } else {
        std::cout << _name << " has no weapon to attack with!" << std::endl;
    }
}