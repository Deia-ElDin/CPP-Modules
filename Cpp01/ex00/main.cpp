#include "Zombie.hpp"

int main(void)
{
    Zombie  *zombie = newZombie("Z 1");

    zombie->announce();
    delete zombie;

    randomChump("Z 2");

    return (0);
}
