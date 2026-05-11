#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap name constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) 
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (this->_energyPoints == 0 || this->_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " is exhausted!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << " ferociously, causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}