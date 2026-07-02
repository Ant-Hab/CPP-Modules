#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
    private:
        Brain* brain{nullptr};

    public:
        Dog();
        Dog(const Dog& src);
        Dog& operator=(const Dog& rhs);
        ~Dog();

        void makeSound() const override;
};
