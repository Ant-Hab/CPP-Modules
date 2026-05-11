#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/* Main entry point to test abstract class instantiation restrictions */
int main()
{
    // const AAnimal* meta = new AAnimal(); // This will fail to compile if uncommented

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();

    delete j;
    delete i;

    return 0;
}