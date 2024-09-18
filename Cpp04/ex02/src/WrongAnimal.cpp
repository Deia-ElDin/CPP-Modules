#include "WrongAnimal.hpp"

void    WrongAnimal::printStatus(const WrongAnimal& wrongAnimal) {
    Utils::printMsg("  Type : " + wrongAnimal.type, "cyan");
}

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    Utils::printMsg("WrongAnimal default constructor called", "yellow");
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
    Utils::printMsg("WrongAnimal type constructor called", "yellow");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    Utils::printMsg("WrongAnimal copy constructor called", "yellow");
}

WrongAnimal&   WrongAnimal::operator=(const WrongAnimal& other) {
    Utils::printMsg("WrongAnimal copy assignment operator called", "yellow");
    
    if (this != &other) this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() { 
    Utils::printMsg("WrongAnimal destructor called", "red"); 
}

void            WrongAnimal::setType(const std::string& type) { 
    this->type = type; 
}

std::string     WrongAnimal::getType() const { 
    return type; 
}

void            WrongAnimal::makeSound() const {
    Utils::printMsg("Some generic wrongAnimal sound!", "blue");
}
