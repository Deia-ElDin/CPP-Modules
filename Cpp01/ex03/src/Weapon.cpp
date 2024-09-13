#include "Weapon.hpp"

Weapon::Weapon() {};
Weapon::Weapon(std::string type) : _type(type) {};
Weapon::~Weapon() {};

// Setters
void                Weapon::setType(std::string type) { 
    _type = type; 
};

// Getters
std::string const&  Weapon::getType(void) { 
    return this->_type; 
};
