#include "ClapTrap.hpp"

// Default Constructor - Initializes base stats for ex00 (10 HP, 10 EP, 0 AD)
ClapTrap::ClapTrap() 
{
    this->_name = "Default";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

// Name Constructor - Initializes custom named ClapTrap with base stats
ClapTrap::ClapTrap(std::string name) 
{
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap name constructor called for " << _name << std::endl;
}

// Copy Constructor - Creates a new instance as a deep copy of an existing one
ClapTrap::ClapTrap(const ClapTrap& other) 
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator - Safely copies attributes preventing self-assignment
ClapTrap& ClapTrap::operator=(const ClapTrap& other) 
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor - Cleans up the instance from the stack
ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

// Attack - Consumes 1 Energy Point to strike a target if alive and charged
void ClapTrap::attack(const std::string& target) 
{
    if (this->_energyPoints == 0 || this->_hitPoints == 0) 
    {
        std::cout << "ClapTrap " << _name << " is out of juice or dead!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// Take Damage - Reduces Hit Points, safely capping out at 0 HP (no underflow)
void ClapTrap::takeDamage(unsigned int amount) 
{
    if (this->_hitPoints <= amount)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage! HP left: " << _hitPoints << std::endl;
}

// Be Repaired - Consumes 1 Energy Point to restore Hit Points if active
void ClapTrap::beRepaired(unsigned int amount) 
{
    if (this->_energyPoints == 0 || this->_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " can't repair itself!" << std::endl;
        return;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself by " << amount 
              << " points! HP is now " << _hitPoints << std::endl;
}