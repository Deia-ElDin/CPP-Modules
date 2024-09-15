#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap robot("Clappy");

    robot.attack("enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.attack("enemy");

    return 0;
}
