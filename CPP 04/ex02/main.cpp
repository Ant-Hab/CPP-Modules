#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 0. ABSTRACT CLASS TEST (EX02) ---\n";
    // UNCOMMENTING THE LINES BELOW MUST CAUSE A COMPILER ERROR!
    // AAnimal abstractAnimal;
    // const AAnimal* meta = new AAnimal();
    std::cout << "AAnimal is abstract. Cannot instantiate it directly. (Uncomment code to verify)\n";

    std::cout << "\n--- 1. SUBJECT TESTS ---\n";
    // Pointers to the abstract base class are perfectly fine!
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    delete j; 
    delete i;

    std::cout << "\n--- 2. ARRAY OF ANIMALS (FARM) ---\n";
    // Array of 10: 5 Dogs, 5 Cats.
    const int farmSize = 10;
    AAnimal* farm[farmSize];
    
    for (int k = 0; k < farmSize / 2; k++)
        farm[k] = new Dog();
    for (int k = farmSize / 2; k < farmSize; k++)
        farm[k] = new Cat();
        
    std::cout << "\nSounds:\n";
    for (int k = 0; k < farmSize; k++)
        farm[k]->makeSound(); // Works perfectly using polymorphism
        
    std::cout << "\nDeleting Farm:\n";
    // Chain destruction: Dog/Cat -> Brain -> AAnimal.
    for (int k = 0; k < farmSize; k++)
        delete farm[k];

    std::cout << "\n--- 3. DEEP COPY TESTS ---\n";
    // {} Deletes the copy early. Crash here if shallow copy!
    Dog originalDog;
    {
        Dog copyDog = originalDog; 
    } 

    // Assignment test. Old brain deleted, new brain copied.
    Cat originalCat;
    Cat assignedCat;
    assignedCat = originalCat;
    
    std::cout << "\n--- CLEANUP ---\n";
    // Stack objects destroy automatically. Crash here if shallow copy!
    return 0;
}
