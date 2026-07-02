#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* brain{nullptr};

    public:
        Cat();
        Cat(const Cat& src);
        Cat& operator=(const Cat& rhs);
        ~Cat();

        void makeSound() const;
};
