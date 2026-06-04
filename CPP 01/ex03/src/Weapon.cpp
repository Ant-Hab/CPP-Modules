#include "Weapon.hpp"

/*
 * Constructor: Initializes the weapon with a specific type.
 */
Weapon::Weapon(const std::string& type) : _type(type) {}

/*
 * Destructor.
 */
Weapon::~Weapon() {}

/*
 * Returns a constant reference to the weapon's current type.
 */
const std::string& Weapon::getType() const
{
	return _type;
}

/*
 * Updates the weapon's type.
 */
void Weapon::setType(const std::string& type)
{
	_type = type;
}