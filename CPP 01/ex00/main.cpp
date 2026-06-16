#include "Zombie.hpp"

/*
 * Main execution block. Tests heap vs stack allocation
 * and ensures proper destruction of both zombies.
 */
int main ()
{
    Zombie* heapZombie = newZombie("Big zombie");
    heapZombie->announce();
    delete (heapZombie);
    
    randomChump("Mini zombie");
    
    return 0;
}
