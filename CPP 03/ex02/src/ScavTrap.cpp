#include "ScavTrap.hpp"

// Default Constructor - Initializes ScavTrap stats (100 HP, 50 EP, 20 AD) via base constructor
ScavTrap::ScavTrap() : ClapTrap() 
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

// Name Constructor - Initializes custom named ScavTrap with ScavTrap stats
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap name constructor called for " << _name << std::endl;
}

// Copy Constructor - Deep copies an existing ScavTrap instance using the base copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) 
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Copy Assignment Operator - Assigns attributes from another ScavTrap instance using base assignment
ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor - Cleans up the ScavTrap instance from the stack
ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

// Attack - Overridden attack function that consumes 1 Energy Point for a ferocious strike
void ScavTrap::attack(const std::string& target) 
{
    if (this->_energyPoints == 0 || this->_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " is exhausted!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << " ferociously, causing " << _attackDamage << " points of damage!" << std::endl;
}

// Guard Gate - Unique ScavTrap action to activate Gate keeper mode
void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}