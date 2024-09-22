#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    Utils::printMsg("Bureaucrat default constructor called", "yellow");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) 
    : _name(name) {
    Utils::printMsg("Bureaucrat constructor called", "yellow");

    if (grade < 1) throw TooHighException(); 
    else if (grade > 150) throw TooLowException();
    
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

int                 Bureaucrat::getGrade() const {
    return _grade;
}

void                Bureaucrat::incrementGrade() {
    _grade == 1 ? throw TooHighException() : _grade--;
}

void                Bureaucrat::decrementGrade() {
    _grade == 150 ? throw TooLowException() : _grade++;
}

const char*         Bureaucrat::TooHighException::what() const _NOEXCEPT {
    return "Error: Grade is too high!";
}

const char*         Bureaucrat::TooLowException::what() const _NOEXCEPT {
    return "Error: Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}