#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->_name = "FragTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    printMsg("FragTrap default constructor called", "yellow");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    printMsg("FragTrap name constructor called", "yellow");
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    printMsg("FragTrap copy constructor called", "yellow");
}

FragTrap&   FragTrap::operator=(const FragTrap& other) {
    printMsg("FragTrap copy assignment operator called", "yellow");
    
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    printMsg("FragTrap destructor called", "red");
}

void    FragTrap::attack(std::string const& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
        return (printMsg("FragTrap " + this->_name + " can't attack!", "red"));

    printMsg("FragTrap " + this->_name + " attacks " + target + " causing " 
    + std::to_string(this->_attackDamage) + " points of damage!", "blue");

    _energyPoints--;
}

void    FragTrap::takeDamage(unsigned int amount) {
    _hitPoints -= amount;

    printMsg("FragTrap " + this->_name + " takes " 
    + std::to_string(amount) + " points of damage!", "red");
}

void    FragTrap::beRepaired(unsigned int amount) {
    if (_energyPoints <= 0) 
        return(printMsg("FragTrap " + _name + " can't repair!", "red"));

    _hitPoints += amount;

    printMsg("FragTrap " + _name + " is repaired by " 
    + std::to_string(amount) + " points!", "green");

    _energyPoints--;
}

void    FragTrap::highFivesGuys() {
    printMsg("FragTrap " + this->_name + " is requesting a high five", "magenta");
}
