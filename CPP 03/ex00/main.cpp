#include "ClapTrap.hpp"

int main() 
{
    std::cout << "--- Initializing ---" << std::endl;
    ClapTrap trappy("Trappy");
    ClapTrap clippy("Clippy");

    std::cout << "\n--- Action Tests ---" << std::endl;
    trappy.attack("a wild bandit");
    trappy.takeDamage(5);
    trappy.beRepaired(3);

    std::cout << "\n--- Energy Depletion Test ---" << std::endl;

    for (int i = 0; i < 10; i++) 
    {
        trappy.attack("the air");
    }

    std::cout << "\n--- Death Test ---" << std::endl;
    clippy.takeDamage(20);
    clippy.beRepaired(5); // Should fail

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}