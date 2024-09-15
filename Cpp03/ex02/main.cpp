#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ScavTrap robot("Clappy");
    FragTrap robot2("Clappy2");

    robot.attack("enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.attack("enemy");
    robot.guardGate();

    robot2.attack("enemy");
    robot2.takeDamage(5);
    robot2.beRepaired(3);
    robot2.attack("enemy");
    robot2.highFivesGuys();

    return 0;
}
