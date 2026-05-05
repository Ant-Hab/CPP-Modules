#include "Zombie.hpp"

/* Tests heap vs stack allocation and ensures proper destruction */
int main(void) 
{
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    randomChump("StackZombie");
    return 0;
}