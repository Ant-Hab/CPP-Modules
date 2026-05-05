#include "HumanA.hpp"

/* Constructor uses initialization list to bind the mandatory weapon reference */
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

/* Displays attack message using the current weapon type */
void HumanA::attack() const 
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}