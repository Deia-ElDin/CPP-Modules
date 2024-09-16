#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap robot("Scavvy");

    ScavTrap::printStatus(robot);
    robot.attack("enemy");
    ScavTrap::printStatus(robot);
    robot.takeDamage(5);
    ScavTrap::printStatus(robot);
    robot.beRepaired(3);
    ScavTrap::printStatus(robot);
    robot.attack("enemy");
    robot.takeDamage(100);
    ScavTrap::printStatus(robot);
    robot.takeDamage(5);
    ScavTrap::printStatus(robot);
    return 0;
}

/*
    Why this (ScavTrap::printStatus(robot)) works ?
        -   Pass-by-reference ensures that the function receives a reference to the actual ScavTrap object, so no slicing occurs.
        -   The ClapTrap class's printStatus() function works with the inherited attributes of ScavTrap since ScavTrap is a subclass of ClapTrap.
        -   Even though you're calling ClapTrap::printStatus(), it correctly accesses the modified values from the ScavTrap object because those values exist in the base class (ClapTrap)
*/
