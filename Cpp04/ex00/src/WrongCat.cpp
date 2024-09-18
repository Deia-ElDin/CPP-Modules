#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    this->type = "WrongCat";
    printMsg("WrongCat default constructor called", "yellow");
}

WrongCat::WrongCat(const std::string& type): WrongAnimal(type) {
    this->type = type;
    printMsg("WrongCat type constructor called", "yellow");
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    this->type = other.type;
    printMsg("WrongCat copy constructor called", "yellow");
}

WrongCat&   WrongCat::operator=(const WrongCat& other) {
    printMsg("WrongCat copy assignment operator called", "yellow");
    
    if (this != &other) this->type = other.type;
    return *this;
}

WrongCat::~WrongCat() {
    printMsg("WrongCat destructor called", "red");
}

void    WrongCat::makeSound() const {
    printMsg("WrongCat Meow Meow!", "blue");
}
