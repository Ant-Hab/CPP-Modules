#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "--- Standard Polymorphism Test ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Type: " << j->getType() << std::endl;
    std::cout << "Type: " << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- Wrong Animal Test (No Virtual) ---" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    std::cout << "Type: " << wrong->getType() << std::endl;
    wrong->makeSound();

    delete wrong;

    return 0;
}