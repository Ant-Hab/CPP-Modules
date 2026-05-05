#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
private:
    std::string _name;

public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};

/* Creates a zombie on the heap and returns a pointer to it */
Zombie* newZombie(std::string name);

/* Creates a zombie on the stack, it announces itself and dies when function ends */
void    randomChump(std::string name);

#endif