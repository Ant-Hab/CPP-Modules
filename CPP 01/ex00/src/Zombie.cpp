#include "Zombie.hpp"

/*
 * Constructor: Initializes the zombie object with the provided name.
 */
Zombie::Zombie(std::string name): _name(name) {}

/*
 * Destructor: Prints a message to announce the zombie's destruction.
 */
Zombie::~Zombie(){
    std::cout << _name << " was destroyed" << std::endl;
}

/*
 * Makes the zombie announce itself with its name and catchphrase.
 */
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}