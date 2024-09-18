#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(): Animal() {
    this->type = "Cat";
    printMsg("Cat default constructor called", "yellow");
}

Cat::Cat(const std::string& type): Animal(type) {
    this->type = type;
    printMsg("Cat type constructor called", "yellow");
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->type = other.type;
    printMsg("Cat copy constructor called", "yellow");
}

Cat&   Cat::operator=(const Cat& other) {
    printMsg("Cat copy assignment operator called", "yellow");
    
    if (this != &other) this->type = other.type;
    return *this;
}

Cat::~Cat() {
    printMsg("Cat destructor called", "red");
}

void    Cat::makeSound() const {
    printMsg("Meow Meow!", "blue");
}
