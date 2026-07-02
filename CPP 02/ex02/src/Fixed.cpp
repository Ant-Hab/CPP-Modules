#include "Fixed.hpp"

// --- Constructors & Destructor ---

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int input) : _fixedPointValue(input << _fractionalBits) {}

Fixed::Fixed(const float input) : _fixedPointValue(roundf(input * (1 << _fractionalBits))) {}

// Using initializer list prevents garbage memory assignments
Fixed::Fixed(const Fixed& other) : _fixedPointValue(other.getRawBits()) {}

Fixed::~Fixed() {}


// --- Assignment Operator ---

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}


// --- Core Member Functions ---

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// --- Comparison Operators ---

bool Fixed::operator>(const Fixed& other) const { return this->_fixedPointValue > other.getRawBits(); }
bool Fixed::operator<(const Fixed& other) const { return this->_fixedPointValue < other.getRawBits(); }
bool Fixed::operator>=(const Fixed& other) const { return this->_fixedPointValue >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed& other) const { return this->_fixedPointValue <= other.getRawBits(); }
bool Fixed::operator==(const Fixed& other) const { return this->_fixedPointValue == other.getRawBits(); }
bool Fixed::operator!=(const Fixed& other) const { return this->_fixedPointValue != other.getRawBits(); }


// --- Arithmetic Operators ---
// Note: Returning by value to avoid dangling references

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const { return Fixed(this->toFloat() / other.toFloat()); }

// Fixed Fixed::operator+(const Fixed& other) const
// {
//     Fixed   result;
//     result.setRawBits(this->_fixedPointValue + other.getRawBits());
//     return result;
// }
// Fixed Fixed::operator-(const Fixed& other) const
// {
//     Fixed   result;
//     result.setRawBits(this->_fixedPointValue - other.getRawBits());
//     return result;
// }
// Fixed Fixed::operator*(const Fixed& other) const
// {
//     Fixed   result;
//     result.setRawBits(this->_fixedPointValue * other.getRawBits() * (1 >> this->_fractionalBits));
//     return result;
// }
// Fixed Fixed::operator/(const Fixed& other) const
// {
//     Fixed   result;
//     result.setRawBits(this->_fixedPointValue * (1 << this->_fractionalBits) / other.getRawBits());
//     return result;
// }


// --- Increment/Decrement Operators ---

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


// --- Static Min/Max Functions ---
// Note: Arguments must be taken by reference to safely return by reference

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}


// --- Stream Overload ---

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
