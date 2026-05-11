#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap name constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

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

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

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

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (this->_hitPoints <= amount)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage! HP left: " << _hitPoints << std::endl;
}

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
