#include "Zombie.hpp"

Zombie::Zombie() {};
Zombie::Zombie(std::string name) : _name(name) {};
Zombie::~Zombie() {};

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}