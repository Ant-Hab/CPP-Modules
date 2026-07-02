#pragma once

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type{"Animal"};

    public:
        Animal();
        Animal(const Animal& src);
        Animal& operator=(const Animal& rhs);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const;
};
