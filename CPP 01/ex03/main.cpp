#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
 * Tests the behavior of objects using references (HumanA) 
 * versus objects using pointers (HumanB) for their attributes.
 */
int main()
{
	{
		Weapon club = Weapon("Sword");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("AK47");
		bob.attack();
	}
	{
		Weapon club = Weapon("Axe");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("Shortgun");
		jim.attack();
	}
	
	return 0;
}