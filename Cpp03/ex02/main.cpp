#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ScavTrap robot("Scavvy");
    FragTrap robot2("Fraggy");

    ScavTrap::printStatus(robot);
    FragTrap::printStatus(robot2);
    robot.attack("enemy");
    ScavTrap::printStatus(robot);
    robot.takeDamage(5);
    ScavTrap::printStatus(robot);
    robot.beRepaired(3);
    ScavTrap::printStatus(robot);
    robot.attack("enemy");
    ScavTrap::printStatus(robot);
    robot.guardGate();

    robot2.attack("enemy");
    FragTrap::printStatus(robot2);
    robot2.takeDamage(5);
    FragTrap::printStatus(robot2);
    robot2.beRepaired(3);
    FragTrap::printStatus(robot2);
    robot2.attack("enemy");
    FragTrap::printStatus(robot2);
    robot2.highFivesGuys();

    return 0;
}
