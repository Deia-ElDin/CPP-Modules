#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(): Animal() {
    this->type = "Dog";
    printMsg("Dog default constructor called", "yellow");
}

Dog::Dog(const std::string& type) : Animal(type) {
    this->type = type;
    printMsg("Dog type constructor called", "yellow");
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->type = other.type;
    printMsg("Dog copy constructor called", "yellow");
}

Dog&   Dog::operator=(const Dog& other) {
    printMsg("Dog copy assignment operator called", "yellow");
    
    if (this != &other) this->type = other.type;
    return *this;
}

Dog::~Dog() {
    printMsg("Dog destructor called", "red");
}

void    Dog::makeSound() const {
    printMsg("Woof!", "blue");
}
