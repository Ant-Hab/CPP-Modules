#include "Fixed.hpp"

// Constructors, Destructor and Conversion from previous ex remain same...
// (Assuming you kept the implementations of toFloat, toInt, etc.)

Fixed::Fixed() : _fixedPointValue(0) {}
Fixed::Fixed(const int input) : _fixedPointValue(input << _fractionalBits) {}
Fixed::Fixed(const float input) : _fixedPointValue(roundf(input * (1 << _fractionalBits))) {}
Fixed::Fixed(const Fixed& other) { *this = other; }
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) this->_fixedPointValue = other.getRawBits();
    return *this;
}
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }
float Fixed::toFloat(void) const { return (float)this->_fixedPointValue / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return this->_fixedPointValue >> _fractionalBits; }

// --- Comparison Operators ---
bool Fixed::operator>(const Fixed& other) const  { return this->_fixedPointValue > other.getRawBits(); }
bool Fixed::operator<(const Fixed& other) const  { return this->_fixedPointValue < other.getRawBits(); }
bool Fixed::operator>=(const Fixed& other) const { return this->_fixedPointValue >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed& other) const { return this->_fixedPointValue <= other.getRawBits(); }
bool Fixed::operator==(const Fixed& other) const { return this->_fixedPointValue == other.getRawBits(); }
bool Fixed::operator!=(const Fixed& other) const { return this->_fixedPointValue != other.getRawBits(); }

// --- Arithmetic Operators ---
Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const { return Fixed(this->toFloat() / other.toFloat()); }

// --- Increment/Decrement ---
// Smallest epsilon is 1 in raw bits (representing 1/256)
Fixed& Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// --- Static Functions ---
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}