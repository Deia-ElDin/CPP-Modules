#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    this->type = "WrongCat";
    Utils::printMsg("WrongCat default constructor called", "yellow");
}

WrongCat::WrongCat(const std::string& type): WrongAnimal(type) {
    this->type = type;
    Utils::printMsg("WrongCat type constructor called", "yellow");
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    this->type = other.type;
    Utils::printMsg("WrongCat copy constructor called", "yellow");
}

WrongCat&   WrongCat::operator=(const WrongCat& other) {
    Utils::printMsg("WrongCat copy assignment operator called", "yellow");
    
    if (this != &other) this->type = other.type;
    return *this;
}

WrongCat::~WrongCat() {
    Utils::printMsg("WrongCat destructor called", "red");
}

void    WrongCat::makeSound() const {
    Utils::printMsg("WrongCat Meow Meow!", "blue");
}
