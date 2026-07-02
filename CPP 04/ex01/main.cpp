#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. SUBJECT TESTS ---\n";
    // Creates Dog/Cat, deletes safely. Watch for leaks.
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; 
    delete i;

    std::cout << "\n--- 2. ARRAY OF ANIMALS (FARM) ---\n";
    // Array of 10: 5 Dogs, 5 Cats.
    const int farmSize = 10;
    Animal* farm[farmSize];
    
    for (int k = 0; k < farmSize / 2; k++)
        farm[k] = new Dog();
    for (int k = farmSize / 2; k < farmSize; k++)
        farm[k] = new Cat();
        
    std::cout << "\nSounds:\n";
    for (int k = 0; k < farmSize; k++)
        farm[k]->makeSound();
        
    std::cout << "\nDeleting Farm:\n";
    // Chain destruction: Animal -> Brain.
    for (int k = 0; k < farmSize; k++)
        delete farm[k];

    std::cout << "\n--- 3. DEEP COPY TESTS ---\n";
    // Deletes the copy early. Crash here = shallow copy!
    Dog originalDog;
    {
        Dog copyDog = originalDog; 
    } 

    // Assignment test. Old brain deleted, new brain copied.
    Cat originalCat;
    Cat assignedCat;
    assignedCat = originalCat;
    
    std::cout << "\n--- CLEANUP ---\n";
    // Stack objects destroy automatically. Crash here = shallow copy!
    return 0;
}
