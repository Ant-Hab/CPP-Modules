#include "Zombie.hpp"

/*
 * Creates a zombie on the heap and returns a pointer to it.
 * The caller is responsible for manually deleting this zombie to free memory.
 */
Zombie* newZombie( std::string name )
{
    Zombie* creature = new Zombie(name);
    return (creature);
}