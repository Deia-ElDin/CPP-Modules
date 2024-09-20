#include "Cat.hpp"

Cat::Cat(): Animal() {
    Utils::printMsg("Cat default constructor called", "yellow");

    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const std::string& type): Animal(type) {
    Utils::printMsg("Cat type constructor called", "yellow");

    this->type = type;
    this->brain = new Brain(); 
}

Cat::Cat(const Cat& other) : Animal(other) {
    Utils::printMsg("Cat copy constructor called", "yellow");
    
    this->type = other.type;
    this->brain = new Brain(*other.brain);
}

Cat&   Cat::operator=(const Cat& other) {
    Utils::printMsg("Cat copy assignment operator called", "yellow");
    
    if (this != &other) { 
        Animal::operator=(other);
        this->type = other.type;    // Redundant, but kept for clarity.

        delete this->brain; 
        this->brain = new Brain(*other.brain);  // Deep copy of dynamic memory.
    }
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    Utils::printMsg("Cat destructor called", "red");
}

void    Cat::makeSound() const {
    Utils::printMsg("Meow Meow!", "blue");
}

void    Cat::setIdea(const std::string& idea) const {
    this->brain->setIdea(idea);
}

void    Cat::setBrain(void) const {
    this->brain->setBrain(this->type);
}

void    Cat::printIdeas(void) const {
    this->brain->printIdeas();
}

/*
    -   Base class assignment (Animal::operator=(other)): 
        Ensures that all members of the base class (Animal) are properly copied, such as the type.
    -   Deep copy of dynamic memory (Brain):
        .   Delete the old memory (delete this->brain) to prevent memory leaks.
        .   Allocate and copy (this->brain = new Brain(*other.brain)) the Brain object so that each Cat has its own independent Brain object.
*/
