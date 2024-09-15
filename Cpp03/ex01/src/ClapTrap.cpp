#include "ClapTrap.hpp"

void    printMsg(const std::string& msg, const std::string& color) {
    std::string textBold = "\033[1m" ;
    std::string textColor;
    std::string textReset = "\033[0m";

    if (color == "green") textColor = "\033[32m";           // Green
    else if (color == "red") textColor = "\033[31m";        // Red
    else if (color == "yellow") textColor = "\033[33m";     // Yellow
    else if (color == "blue") textColor = "\033[34m";       // Blue
    else if (color == "magenta") textColor = "\033[35m";    // Magenta
    else textColor = "\033[37m";                            // White

    std::string fullMsg = textBold + textColor + msg + textReset;
    
    std::cout << fullMsg << std::endl; 
}

ClapTrap::ClapTrap() 
    : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    printMsg("ClapTrap default constructor called", "yellow");
}

ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    printMsg("ClapTrap name constructor called", "yellow");
}

ClapTrap::ClapTrap(const ClapTrap& other) : 
    _name(other._name), 
    _hitPoints(other._hitPoints), 
    _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage) {
    printMsg("ClapTrap copy constructor called", "yellow");
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& other) {
    printMsg("ClapTrap copy assignment operator called", "yellow");
    
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    printMsg("ClapTrap destructor called", "red");
}

void    ClapTrap::attack(std::string const& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
        return (printMsg("ClapTrap " + this->_name + " can't attack!", "red"));

    printMsg("ClapTrap " + this->_name + " attacks " + target + " causing " 
    + std::to_string(this->_attackDamage) + " points of damage!", "blue");

    _energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    _hitPoints -= amount;

    printMsg("ClapTrap " + this->_name + " takes " 
    + std::to_string(amount) + " points of damage!", "red");
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints <= 0) 
        return(printMsg("ClapTrap " + _name + " can't repair!", "red"));

    _hitPoints += amount;

    printMsg("ClapTrap " + _name + " is repaired by " 
    + std::to_string(amount) + " points!", "green");

    _energyPoints--;
}

std::string ClapTrap::getName() const {
    return _name;
}

int         ClapTrap::getHitPoints() const {
    return _hitPoints;
}

int         ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

int         ClapTrap::getAttackDamage() const {
    return _attackDamage;
}

void        ClapTrap::setName(std::string& name) {
    _name = name;
}

void        ClapTrap::setHitPoints(int hitPoints) {
    _hitPoints = hitPoints;
}

void        ClapTrap::setEnergyPoints(int energyPoints) {
    _energyPoints = energyPoints;
}

void        ClapTrap::setAttackDamage(int attackDamage) {
    _attackDamage = attackDamage;
}

