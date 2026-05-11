#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/* Main testing deep copy logic and polymorphism */
int main()
{
    const int count = 4;
    Animal* animals[count];

    for (int i = 0; i < count; i++) {
        if (i < count / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->ideas[0] = "Original Idea";

    Dog* copyDog = new Dog(*originalDog);
    std::cout << "Copy Idea: " << copyDog->getBrain()->ideas[0] << std::endl;

    originalDog->getBrain()->ideas[0] = "Modified Idea";
    std::cout << "Original Idea changed: " << originalDog->getBrain()->ideas[0] << std::endl;
    std::cout << "Copy Idea (must stay same): " << copyDog->getBrain()->ideas[0] << std::endl;

    delete originalDog;
    delete copyDog;

    std::cout << "\n--- Cleanup ---" << std::endl;
    for (int i = 0; i < count; i++)
        delete animals[i];

    return 0;
}