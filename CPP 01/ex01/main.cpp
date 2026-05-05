#include "Zombie.hpp"

/* Tests the creation and destruction of a zombie horde */
int main(void) 
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "Horde_Member");

    for (int i = 0; i < N; i++) 
    {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}