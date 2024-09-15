#include "Fixed.hpp"

void Fixed::printMsg(const std::string& msg, const std::string& color) {
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

Fixed::Fixed() : _fixedPointValue(0) {
    printMsg("Default constructor called", "yellow");
}

Fixed::Fixed(const int value) {
    printMsg("Int constructor called", "yellow");
    this->_fixedPointValue = value << _fractionalBits;
}                

Fixed::Fixed(const float value) {
    printMsg("float constructor called", "yellow");
    this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
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

// Comparison operators
bool    Fixed::operator>(const Fixed &original) const {
    return this->_fixedPointValue > original.getRawBits();
}

bool    Fixed::operator<(const Fixed &original) const {
    return this->_fixedPointValue < original.getRawBits();
}

bool    Fixed::operator>=(const Fixed &original) const {
    return this->_fixedPointValue >= original.getRawBits();
}

bool    Fixed::operator<=(const Fixed &original) const {
    return this->_fixedPointValue <= original.getRawBits();
}

bool    Fixed::operator==(const Fixed &original) const {
    return this->_fixedPointValue == original.getRawBits();
}

bool    Fixed::operator!=(const Fixed &original) const {
    return this->_fixedPointValue != original.getRawBits();
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &original) const {
    return Fixed(this->toFloat() + original.toFloat());
}

Fixed Fixed::operator-(const Fixed &original) const {
    return Fixed(this->toFloat() - original.toFloat());
}

Fixed Fixed::operator*(const Fixed &original) const {
    return Fixed(this->toFloat() * original.toFloat());
}

Fixed Fixed::operator/(const Fixed &original) const {
    return Fixed(this->toFloat() / original.toFloat());
}

// Increment/Decrement operators
Fixed &Fixed::operator++() { 
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}

void    Fixed::setRawBits(int const raw) {
    printMsg("setRawBits member function called", "magenta");
    this->_fixedPointValue = raw;
}

int     Fixed::getRawBits(void) const {
    printMsg("getRawBits member function called", "magenta");
    return this->_fixedPointValue;
}

float   Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int     Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// Min/Max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}
