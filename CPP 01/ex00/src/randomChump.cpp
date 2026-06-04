#include "Zombie.hpp"

/*
 * Creates a zombie locally on the stack. 
 * It announces itself and is destroyed automatically when the function ends.
 */
void randomChump( std::string name )
{
    Zombie creature(name);
    creature.announce();
}