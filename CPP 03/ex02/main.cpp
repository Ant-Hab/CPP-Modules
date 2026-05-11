#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "--- CONSTRUCTING FRAGTRAP ---" << std::endl;
    FragTrap frag("Fragger");

    std::cout << "\n--- ACTIONS ---" << std::endl;
    frag.attack("a group of Psycho Skags");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n--- TESTING CHAINING WITH SCAVTRAP ---" << std::endl;
    ScavTrap scav("Scavvy");
    scav.guardGate();

    std::cout << "\n--- DESTRUCTION ---" << std::endl;
    return 0;
}