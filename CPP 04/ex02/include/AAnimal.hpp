#pragma once

#include <iostream>
#include <string>

class AAnimal {
    protected:
        std::string type{"AAnimal"};

    public:
        AAnimal();
        AAnimal(const AAnimal& src);
        AAnimal& operator=(const AAnimal& rhs);
        virtual ~AAnimal();
        
        std::string getType() const;
        virtual void makeSound() const = 0; 
};
