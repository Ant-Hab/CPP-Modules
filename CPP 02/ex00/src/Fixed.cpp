#include "Fixed.hpp"

/* Default constructor initializing value to 0 */
Fixed::Fixed() : _fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

/* Copy constructor calling the assignment operator */
Fixed::Fixed(const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/* Copy assignment operator with self-assignment check */
Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

/* Destructor */
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

/* Returns the raw value of the fixed-point value */
int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

/* Sets the raw value of the fixed-point number */
void Fixed::setRawBits(int const raw) 
{
    this->_fixedPointValue = raw;
}