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

void   ScavTrap::attack(std::string const& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
        return (printMsg("ScavTrap " + this->_name + " can't attack!", "red"));

    printMsg("ScavTrap " + this->_name + " attacks " + target + " causing " 
    + std::to_string(this->_attackDamage) + " points of damage!", "blue");

    _energyPoints--;
}

void   ScavTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) 
        return(printMsg("ScavTrap " + _name + " can't repair!", "red"));

    _hitPoints -= amount;

    printMsg("ScavTrap " + this->_name + " takes " 
    + std::to_string(amount) + " points of damage!", "red");
}

void   ScavTrap::beRepaired(unsigned int amount) {
    if (_energyPoints <= 0) 
        return(printMsg("ScavTrap " + _name + " can't repair!", "red"));

    _hitPoints += amount;

    printMsg("ScavTrap " + _name + " is repaired by " 
    + std::to_string(amount) + " points!", "green");
}

void   ScavTrap::guardGate() {
    printMsg("ScavTrap " + this->_name + " has entered in Gate keeper mode", "magenta");
}