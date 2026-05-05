#include "Zombie.hpp"

/* Creates a zombie on the stack, it announces itself and dies when function ends */
void randomChump(std::string name) 
{
    Zombie stackZombie(name);
    stackZombie.announce();
}