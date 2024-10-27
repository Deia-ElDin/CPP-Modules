#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5), _target("default") {
    Utils::printMsg("Presidential Pardon Form default constructor called", "yellow");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {
        Utils::printMsg("Presidential Pardon Form parameter constructor called", "yellow");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
    Utils::printMsg("Presidential Pardon Form copy constructor called", "yellow");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    Utils::printMsg("Presidential Pardon Form assignment operator called", "yellow");

    if (this != &other) {
        AForm::operator=(other); 
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    Utils::printMsg("Presidential Pardon Form destructor called", "purple");
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned()) throw FormNotSignedException();

    if (executor.getGrade() > getExecuteGrade()) throw GradeTooLowException();

    Utils::printMsg(_target + " has been pardoned by Zaphod Beeblebrox", "green");
}
