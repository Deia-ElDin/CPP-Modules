#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Utils.hpp"

Intern::Intern() {
    Utils::printMsg("Intern default constructor called.", "yellow");
}

Intern::Intern(const Intern& other) {
    Utils::printMsg("Intern copy constructor called.", "yellow");
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    Utils::printMsg("Intern assignment operator called.", "yellow");
    (void)other;
    return *this;
}

Intern::~Intern() {
    Utils::printMsg("Intern destructor called.", "purple");
}

AForm*  createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm*  createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm*  createPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm*  Intern::makeForm(const std::string& formName, const std::string& target) const {
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    AForm* (*formCreators[3])(const std::string&) = {
        createShrubberyForm,
        createRobotomyForm,
        createPardonForm
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            Utils::printMsg("Intern creates " + formName, "green");
            return formCreators[i](target);
        }
    }

    Utils::printErr("Error: Form name '" + formName + "' not recognized.");
    return NULL;
}
