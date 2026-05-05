#include "Zombie.hpp"

/* Creates a zombie on the heap and returns a pointer to it */
Zombie* newZombie(std::string name) 
{
    return new Zombie(name);
}