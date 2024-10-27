#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), _target("default") {
    Utils::printMsg("Robotomy Request Form default constructor called", "yellow");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45), _target(target) {
        Utils::printMsg("Robotomy Request Form parameter constructor called", "yellow");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {
    Utils::printMsg("Robotomy Request Form copy constructor called", "yellow");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    Utils::printMsg("Robotomy Request Form assignment operator called", "yellow");

    if (this != &other) {
        AForm::operator=(other);  // Call base class assignment operator
        _target = other._target;
    }
    return *this;
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