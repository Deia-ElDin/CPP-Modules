#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    Utils::printMsg("Bureaucrat default constructor called", "yellow");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) 
    : _name(name) {
    Utils::printMsg("Bureaucrat constructor called", "yellow");

    if (grade < 1) throw GradeTooHighException(); 
    else if (grade > 150) throw GradeTooLowException();
    
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
    : _name(other._name), _grade(other._grade) {
    Utils::printMsg("Bureaucrat copy constructor called", "yellow");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    Utils::printMsg("Bureaucrat assignation operator called", "yellow");

    if (this != &other) _grade = other._grade; // only grade is assignable since _name is const
    return *this;
}

Bureaucrat::~Bureaucrat() {
    Utils::printMsg("Bureaucrat destructor called", "purple");
}

const std::string&  Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void    Bureaucrat::incrementGrade() {
    _grade == 1 ? throw GradeTooHighException() : _grade--;
}

void    Bureaucrat::decrementGrade() {
    _grade == 150 ? throw GradeTooLowException() : _grade++;
}

void    Bureaucrat::signForm(bool isSigned, const std::string &formName) const {
    if (isSigned)
        Utils::printMsg(_name + " signed " + formName, "green");
    else 
        Utils::printMsg(_name + " couldn’t sign " + formName + " because his grade is too low (" + Utils::toStr(_grade) + ").", "red"); 
}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
    return "Error: Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
    return "Error: Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}