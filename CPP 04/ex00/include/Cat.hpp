#pragma once

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(const Cat& src);
        Cat& operator=(const Cat& rhs);
        ~Cat();

        void makeSound() const;
};
