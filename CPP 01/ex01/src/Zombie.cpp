#include "Zombie.hpp"

/* Default constructor required for array allocation */
Zombie::Zombie() {}
/* Destructor prints name to verify all N zombies are freed */
Zombie::~Zombie() 
{
    std::cout << _name << ": has been destroyed" << std::endl;
}
/* Sets the name for zombies created in a horde */
void Zombie::setName(std::string name) 
{
    _name = name;
}
/* Standard announcement */
void Zombie::announce(void) 
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}