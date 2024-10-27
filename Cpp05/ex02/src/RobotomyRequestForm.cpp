#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm(target, 72, 45), _target(target) {
        Utils::printMsg("Robotomy Request Form parameter constructor called", "yellow");
}

RobotomyRequestForm::~RobotomyRequestForm() {
    Utils::printMsg("Robotomy Request Form destructor called", "purple");
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned()) throw FormNotSignedException();

    if (executor.getGrade() > getExecuteGrade()) throw GradeTooLowException();

    bool    robotomySuccessfully = Utils::getRandomNumber(0, 1) == 1;

    robotomySuccessfully
        ? Utils::printMsg(_target + " has been robotomized successfully", "green")
        : Utils::printMsg(_target + " robotomy failed", "red");
}