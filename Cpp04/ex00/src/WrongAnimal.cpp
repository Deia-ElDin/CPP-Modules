#include "WrongAnimal.hpp"

void   WrongAnimal::printMsg(const std::string& msg, const std::string& color) {
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

void    WrongAnimal::printStatus(const WrongAnimal& wrongAnimal) {
    printMsg("  Type : " + wrongAnimal.type, "cyan");
}

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    printMsg("WrongAnimal default constructor called", "yellow");
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
    printMsg("WrongAnimal type constructor called", "yellow");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    printMsg("WrongAnimal copy constructor called", "yellow");
}

WrongAnimal&   WrongAnimal::operator=(const WrongAnimal& other) {
    printMsg("WrongAnimal copy assignment operator called", "yellow");
    
    if (this != &other) this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() { 
    printMsg("WrongAnimal destructor called", "red"); 
}

void            WrongAnimal::setType(const std::string& type) { 
    this->type = type; 
}

std::string     WrongAnimal::getType() const { 
    return type; 
}

void            WrongAnimal::makeSound() const {
    printMsg("Some generic wrongAnimal sound!", "blue");
}
