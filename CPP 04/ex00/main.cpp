#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "--- STANDARD ANIMAL TESTS ---\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\nTypes:\n";
    std::cout << j->getType() << " " << "\n";
    std::cout << i->getType() << " " << "\n";
    
    std::cout << "\nSounds:\n";
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    std::cout << "\nCleaning up:\n";
    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- WRONG ANIMAL TESTS ---\n";
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
    
    std::cout << "\nTypes:\n";
    std::cout << wrongI->getType() << " " << "\n";
    
    std::cout << "\nSounds:\n";
    wrongI->makeSound(); 
    wrongMeta->makeSound();
    
    std::cout << "\nCleaning up:\n";
    delete wrongMeta;
    delete wrongI;

    return 0;
}
