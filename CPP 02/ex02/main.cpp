#include <iostream>
#include "Fixed.hpp"

int main(void) 
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    /* 1. Arithmetic Operators (+, -, /) */
    Fixed sum = a + b;
    Fixed diff = b - a;
    Fixed div = b / Fixed(2);
    std::cout << "Sum (+): " << sum << std::endl;
    std::cout << "Difference (-): " << diff << std::endl;
    std::cout << "Division(/): " << div << std::endl;


    /* 2. Decrement Operators (Pre-decrement and Post-decrement) */
    std::cout << "Pre-decrement (--a): " << --a << std::endl;
    std::cout << "Current a: " << a << std::endl;
    std::cout << "Post-decrement (a--): " << a-- << std::endl;
    std::cout << "Current a: " << a << std::endl;


    /* 3. Comparison Operators (Will output 1 for true, 0 for false) */
    std::cout << "Is a > b ?  " << (a > b) << std::endl;
    std::cout << "Is a < b ?  " << (a < b) << std::endl;
    std::cout << "Is a >= b ? " << (a >= b) << std::endl;
    std::cout << "Is a <= b ? " << (a <= b) << std::endl;
    std::cout << "Is a == b ? " << (a == b) << std::endl;
    std::cout << "Is a != b ? " << (a != b) << std::endl;

    /* 4. Static Min Function */
    std::cout << "Min between a and b: " << Fixed::min(a, b) << std::endl;
    std::cout << "Max between a and b: " << Fixed::max(a, b) << std::endl;

    return 0;
}