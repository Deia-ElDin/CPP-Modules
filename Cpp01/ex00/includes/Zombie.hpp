#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;
        std::string _type;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();

        void    announce(void);
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif // __ZOMBIE_HPP__