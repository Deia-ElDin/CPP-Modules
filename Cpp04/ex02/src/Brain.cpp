#include "Brain.hpp"

Brain::Brain() {
    Utils::printMsg("Brain default constructor called", "yellow");
}

Brain::Brain(const Brain& other) {
    Utils::printMsg("Brain copy constructor called", "yellow");

    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    Utils::printMsg("Brain copy assignment operator called", "yellow");

    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    Utils::printMsg("Brain destructor called", "red");
}

void    Brain::setIdea(const std::string& idea)
{
    for (int i = 0; i < 100; ++i) {
        if (this->ideas[i].empty()) {
            this->ideas[i] = idea;
            return;
        }
    }
    Utils::printMsg("Brain is full, can't add more ideas.", "red");
}

void    Brain::setBrain(const std::string& animalType) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = animalType + " idea " + std::to_string(i + 1);
    }
}

void    Brain::printIdeas() const {
    for (int i = 0; i < 100; ++i) {
        if (ideas[i].empty()) break;
        Utils::printMsg("Idea " + std::to_string(i + 1) + ": " + ideas[i], "magenta");
    }
}
