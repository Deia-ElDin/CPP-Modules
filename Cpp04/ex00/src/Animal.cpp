#include "Animal.hpp"

void   Animal::printMsg(const std::string& msg, const std::string& color) {
    std::string textBold = "\033[1m";
    std::string textColor;
    std::string textReset = "\033[0m";

    if (color == "green") textColor = "\033[32m";           // Green
    else if (color == "red") textColor = "\033[31m";        // Red
    else if (color == "yellow") textColor = "\033[33m";     // Yellow
    else if (color == "blue") textColor = "\033[34m";       // Blue
    else if (color == "magenta") textColor = "\033[35m";    // Magenta
    else if (color == "cyan") textColor = "\033[36m";       // Cyan
    else textColor = "\033[37m";                            // White

    std::string fullMsg = textBold + textColor + msg + textReset;
    
    std::cout << fullMsg << std::endl; 
}

void    Animal::printStatus(const Animal& animal) {
    printMsg("  Type : " + animal.type, "cyan");
}

Animal::Animal() : type("Animal") {
    printMsg("Animal default constructor called", "yellow");
}

Animal::Animal(const std::string& type) : type(type) {
    printMsg("Animal type constructor called", "yellow");
}

Animal::Animal(const Animal& other) : type(other.type) {
    printMsg("Animal copy constructor called", "yellow");
}

Animal&   Animal::operator=(const Animal& other) {
    printMsg("Animal copy assignment operator called", "yellow");
    
    if (this != &other) this->type = other.type;
    return *this;
}

Animal::~Animal() { 
    printMsg("Animal destructor called", "red"); 
}

void            Animal::setType(const std::string& type) { 
    this->type = type; 
}

std::string     Animal::getType() const { 
    return type; 
}

void            Animal::makeSound() const {
    printMsg("Some generic animal sound!", "blue");
}
