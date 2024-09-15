#include "Fixed.hpp"

void Fixed::printMsg(const std::string& msg, const std::string& color) {
    std::string textColor;

    if (color == "green") textColor = "\033[32m";           // Green
    else if (color == "red") textColor = "\033[31m";        // Red
    else if (color == "yellow") textColor = "\033[33m";     // Yellow
    else if (color == "blue") textColor = "\033[34m";       // Blue
    else if (color == "magenta") textColor = "\033[35m";    // Magenta
    else textColor = "\033[37m";                            // White

    std::cout << "\033[1m" + textColor + msg + "\033[0m" << std::endl; 
}

Fixed::Fixed() : _fixedPointValue(0) {
    printMsg("Default constructor called", "yellow");
}

Fixed::Fixed(const Fixed &original) : _fixedPointValue(original._fixedPointValue) {
    printMsg("Copy constructor called","yellow");
}

Fixed   &Fixed::operator=(const Fixed &original) {
    printMsg("Copy assignment operator called", "yellow");
    if (this != &original) this->_fixedPointValue = original.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    printMsg("Destructor called", "red");
}

void    Fixed::setRawBits(int const raw) {
    printMsg("setRawBits member function called", "magenta");
    this->_fixedPointValue = raw;
}

int     Fixed::getRawBits(void) const {
    printMsg("getRawBits member function called", "magenta");
    return this->_fixedPointValue;
}