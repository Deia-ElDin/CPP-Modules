#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->_name = "ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    printMsg("ScavTrap default constructor called", "yellow");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    printMsg("ScavTrap name constructor called", "yellow");
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    printMsg("ScavTrap copy constructor called", "yellow");
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& other) {
    printMsg("ScavTrap copy assignment operator called", "yellow");
    
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    printMsg("ScavTrap destructor called", "red");
}

void   ScavTrap::guardGate() {
    printMsg("ScavTrap " + this->_name + " has entered in Gate keeper mode", "magenta");
}