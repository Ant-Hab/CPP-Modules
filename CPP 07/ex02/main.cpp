#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

int main() {
    std::cout << "--- Testing Default Constructor ---" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    try {
        emptyArray[0] = 1;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] (default initialized): " << intArray[i] << std::endl;
        intArray[i] = i * 10;
    }

    std::cout << "\n--- Testing Copy Constructor (Deep Copy) ---" << std::endl;
    Array<int> copyArray(intArray);
    copyArray[0] = 999; // Modify copy
    std::cout << "intArray[0] (should be 0): " << intArray[0] << std::endl;
    std::cout << "copyArray[0] (should be 999): " << copyArray[0] << std::endl;

    std::cout << "\n--- Testing Assignment Operator (Deep Copy) ---" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    assignedArray[1] = 888; // Modify assigned
    std::cout << "intArray[1] (should be 10): " << intArray[1] << std::endl;
    std::cout << "assignedArray[1] (should be 888): " << assignedArray[1] << std::endl;

    std::cout << "\n--- Testing Out of Bounds ---" << std::endl;
    try {
        std::cout << "Trying to access intArray[10]..." << std::endl;
        intArray[10] = 42;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Const Array ---" << std::endl;
    const Array<int> constArray(intArray);
    std::cout << "constArray[2]: " << constArray[2] << std::endl;
    // constArray[2] = 5; // Un-commenting this should cause a compilation error!

    std::cout << "\n--- Testing Complex Types (std::string) ---" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "C++";
    strArray[2] = "Templates";
    for (unsigned int i = 0; i < strArray.size(); i++) {
        std::cout << "strArray[" << i << "]: " << strArray[i] << std::endl;
    }

    return 0;
}