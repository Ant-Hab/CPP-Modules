#include <iostream>
#include <string>

/**
 * This program demonstrates that a variable, its pointer, and its reference
 * all point to the same location in memory.
 */
int main(void)
{
    std::string     str = "HI THIS IS BRAIN";
    std::string*    stringPTR = &str;
    std::string&    stringREF = str;

    // Outputting the memory addresses
    std::cout << "Memory address of the string variable:  " << &str << std::endl;
    std::cout << "Memory address held by stringPTR:       " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:       " << &stringREF << std::endl;

    std::cout << std::endl;

    // Outputting the values
    std::cout << "Value of the string variable:           " << str << std::endl;
    std::cout << "Value pointed to by stringPTR:          " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:          " << stringREF << std::endl;

    return 0;
}