#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
    protected:
        std::string type{"WrongAnimal"};

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& src);
        WrongAnimal& operator=(const WrongAnimal& rhs);
        ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
};
