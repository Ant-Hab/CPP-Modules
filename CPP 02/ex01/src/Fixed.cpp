#include "Fixed.hpp"

/* Constructors & Destructor */
Fixed::Fixed() : _fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input) 
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = input << _fractionalBits;
}

Fixed::Fixed(const float input) 
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(input * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

/* Conversion Functions */
float Fixed::toFloat(void) const 
{
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const 
{
    return this->_fixedPointValue >> _fractionalBits;
}

/* Raw Bits Accessors */
int Fixed::getRawBits(void) const 
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) 
{
    this->_fixedPointValue = raw;
}

/* Global Operator Overload */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 
{
    os << fixed.toFloat();
    return os;
}