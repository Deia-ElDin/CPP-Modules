#include "Dog.hpp"

Dog::Dog(): Animal() {
    this->type = "Dog";
    this->brain = new Brain();
    Utils::printMsg("Dog default constructor called", "yellow");
}

Dog::Dog(const std::string& type): Animal(type) {
    this->type = type;
    this->brain = new Brain(); 
    Utils::printMsg("Dog type constructor called", "yellow");
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    Utils::printMsg("Dog copy constructor called", "yellow");
}

Dog&   Dog::operator=(const Dog& other) {
    Utils::printMsg("Dog copy assignment operator called", "yellow");
    
    if (this != &other) { 
        Animal::operator=(other);
        this->type = other.type;    // Redundant, but kept for clarity.

        delete this->brain; 
        this->brain = new Brain(*other.brain);  // Deep copy of dynamic memory.
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    Utils::printMsg("Dog destructor called", "red");
}

void    Dog::makeSound() const {
    Utils::printMsg("Bark!", "blue");
}

void    Dog::setIdea(const std::string& idea) {
    this->brain->setIdea(idea);
}

void    Dog::setBrain(void) {
    this->brain->setBrain(this->type);
}

void    Dog::printIdeas(void) const {
    this->brain->printIdeas();
}
