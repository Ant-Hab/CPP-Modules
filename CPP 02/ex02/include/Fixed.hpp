#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Constructors & Destructor
    Fixed();
    Fixed(const int input);
    Fixed(const float input);
    Fixed(const Fixed& other);
    ~Fixed();

    // Assignment Operator
    Fixed& operator=(const Fixed& other);

    // Core Member Functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    // Comparison Operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic Operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/Decrement Operators
    Fixed& operator++(void); // Pre-increment
    Fixed operator++(int);   // Post-increment
    Fixed& operator--(void); // Pre-decrement
    Fixed operator--(int);   // Post-decrement

    // Static Min/Max Functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Output stream overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif