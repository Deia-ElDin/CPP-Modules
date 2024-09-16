#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Clappy");

    robot.attack("enemy");
    ClapTrap::printStatus(robot);
    robot.takeDamage(5);
    ClapTrap::printStatus(robot);
    robot.beRepaired(3);
    ClapTrap::printStatus(robot);
    robot.attack("enemy");
    ClapTrap::printStatus(robot);
    return 0;
}
