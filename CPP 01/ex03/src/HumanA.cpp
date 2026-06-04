#include "HumanA.hpp"

/*
 * Constructor: Initializes HumanA with a name and a required weapon reference.
 */
HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {}

/*
 * Destructor.
 */
HumanA::~HumanA() {}

/*
 * Outputs an attack message using the character's name and current weapon type.
 */
void HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}