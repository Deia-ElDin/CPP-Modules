#include "Intern.hpp"

Intern::Intern() {
    Utils::printMsg("Intern default constructor called.", "yellow");
}

Intern::Intern(const Intern& other) {
    Utils::printMsg("Intern copy constructor called.", "yellow");
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    Utils::printMsg("Intern assignment operator called.", "yellow");
    (void)other;
    return *this;
}

Intern::~Intern() {
    Utils::printMsg("Intern destructor called.", "purple");
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    if (formName == "shrubbery creation") {
        Utils::printMsg("Intern creates ShrubberyCreationForm", "cyan");
        return new ShrubberyCreationForm(target);
    } 
    else if (formName == "robotomy request") {
        Utils::printMsg("Intern creates RobotomyRequestForm", "cyan");
        return new RobotomyRequestForm(target);
    } 
    else if (formName == "presidential pardon") {
        Utils::printMsg("Intern creates PresidentialPardonForm", "cyan");
        return new PresidentialPardonForm(target);
    } 
    else {
        Utils::printErr("Error: Form name '" + formName + "' is invalid.");
        return nullptr;
    }
}
