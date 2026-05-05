#include "Zombie.hpp"

/* Initializes the zombie with a name */
Zombie::Zombie(std::string name) : _name(name) {}

/* Prints a destruction message to track the object's lifetime during execution */
Zombie::~Zombie() 
{
    std::cout << _name << ": has been destroyed" << std::endl;
}

/* Outputs the zombie's name followed by the specific announcement string */
void Zombie::announce(void) 
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}