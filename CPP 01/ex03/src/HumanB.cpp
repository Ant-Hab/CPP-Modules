#include "HumanB.hpp"

/*
 * Constructor: Initializes HumanB with a name and sets their weapon pointer to NULL.
 */
HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

/*
 * Destructor.
 */
HumanB::~HumanB() {}

/*
 * Outputs an attack message if armed, or an unarmed message if the weapon pointer is NULL.
 */
void HumanB::attack() const
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}

/*
 * Equips HumanB with a weapon by storing its memory address in the pointer.
 */
void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}