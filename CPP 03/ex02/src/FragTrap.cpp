#include "FragTrap.hpp"

// Default Constructor - Initializes FragTrap stats (100 HP, 100 EP, 30 AD) via base constructor
FragTrap::FragTrap() : ClapTrap() 
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

// Name Constructor - Initializes custom named FragTrap with FragTrap stats
FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap name constructor called for " << _name << std::endl;
}

// Copy Constructor - Deep copies an existing FragTrap instance using the base copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// Copy Assignment Operator - Assigns attributes from another FragTrap instance using base assignment
FragTrap& FragTrap::operator=(const FragTrap& other) 
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor - Cleans up the FragTrap instance from the stack
FragTrap::~FragTrap() 
{
    std::cout << "FragTrap destructor called" << std::endl;
}

// High Fives Guys - Unique FragTrap action to display an enthusiastic high five request
void FragTrap::highFivesGuys(void) 
{
    std::cout << "FragTrap " << _name << " is enthusiastically requesting a high five! 🖐️" << std::endl;
}