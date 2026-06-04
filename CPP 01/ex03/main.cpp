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
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	
	return 0;
}