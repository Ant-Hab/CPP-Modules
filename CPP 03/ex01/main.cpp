#include "ScavTrap.hpp"

int main() 
{
    std::cout << "--- CREATING SCAVTRAP ---" << std::endl;
    ScavTrap serena("Serena");

    std::cout << "\n--- TESTING ACTIONS ---" << std::endl;
    serena.attack("the gate");
    serena.beRepaired(10);
    serena.guardGate();
    serena.takeDamage(50);

    std::cout << "\n--- DESTRUCTORS ---" << std::endl;
    return 0;
}