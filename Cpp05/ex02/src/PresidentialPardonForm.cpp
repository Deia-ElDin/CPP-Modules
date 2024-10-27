#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(target, 25, 5), _target(target) {
        Utils::printMsg("Presidential Pardon Form parameter constructor called", "yellow");
}

PresidentialPardonForm::~PresidentialPardonForm() {
    Utils::printMsg("Presidential Pardon Form destructor called", "purple");
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned()) throw FormNotSignedException();

    if (executor.getGrade() > getExecuteGrade()) throw GradeTooLowException();

    Utils::printMsg(_target + " has been pardoned by Zaphod Beeblebrox", "green");
}
