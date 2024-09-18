#include "Animal.hpp"

void    Animal::printStatus(const Animal& animal) {
    Utils::printMsg("  Type : " + animal.type, "cyan");
}

Animal::Animal() : type("Animal") {
    Utils::printMsg("Animal default constructor called", "yellow");
}

Animal::Animal(const std::string& type) : type(type) {
    Utils::printMsg("Animal type constructor called", "yellow");
}

Animal::Animal(const Animal& other) : type(other.type) {
    Utils::printMsg("Animal copy constructor called", "yellow");
}

Animal&   Animal::operator=(const Animal& other) {
    Utils::printMsg("Animal copy assignment operator called", "yellow");
    
    if (this != &other) this->type = other.type;
    return *this;
}

Animal::~Animal() { 
    Utils::printMsg("Animal destructor called", "red"); 
}

void        Animal::setType(const std::string& type) { 
    this->type = type; 
}

std::string Animal::getType() const { 
    return type; 
}

void        Animal::makeSound() const {
    Utils::printMsg("Some generic animal sound!", "blue");
}
