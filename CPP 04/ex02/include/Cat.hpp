#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain* brain{nullptr};

    public:
        Cat();
        Cat(const Cat& src);
        Cat& operator=(const Cat& rhs);
        ~Cat();

        void makeSound() const override;
};
