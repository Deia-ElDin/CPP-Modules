#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Clappy");

    robot.attack("enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.attack("enemy");

    return 0;
}
