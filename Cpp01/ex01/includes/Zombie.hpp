#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

#include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();

        void    setName(std::string name);
        void    announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif // __ZOMBIE_HPP__