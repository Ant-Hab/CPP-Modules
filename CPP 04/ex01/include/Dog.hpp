#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* brain{nullptr};

    public:
        Dog();
        Dog(const Dog& src);
        Dog& operator=(const Dog& rhs);
        ~Dog();

        void makeSound() const;
};
