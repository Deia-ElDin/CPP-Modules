#include "Form.hpp"

Form::Form()
    : _name("Default Form"), _isSigned(false), _signGrade(150), _executeGrade(150) {
    Utils::printMsg("Form default constructor called", "yellow");
}

Form::Form(
    const std::string&  name,
    bool                isSigned,
    const int           signGrade,
    const int           executeGrade
) : _name(name), _isSigned(isSigned), _signGrade(signGrade), _executeGrade(executeGrade) {
    Utils::printMsg("Form parameter constructor called", "yellow");

    if (name.empty()) throw EmptyNameException();
    else if (isSigned) throw SignedFormException();
    else if (signGrade < 1 || executeGrade < 1) throw GradeTooHighException(); 
    else if (signGrade > 150 || executeGrade > 150) throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), 
      _isSigned(other._isSigned), 
      _signGrade(other._signGrade), 
      _executeGrade(other._executeGrade) {
    Utils::printMsg("Form copy constructor called", "yellow");
}

Form& Form::operator=(const Form& other) {
    Utils::printMsg("Form assignation operator called", "yellow");

    if (this != &other) _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {
    Utils::printMsg("Form destructor called", "purple");
}

const   std::string	Form::getName() const {
    return _name;
}

bool    Form::getIsSigned() const {
    return _isSigned;
}

int     Form::getSignGrade() const {
    return _signGrade;
}

int     Form::getExecuteGrade() const {
    return _executeGrade;
}

void    Form::beSigned(Bureaucrat &bureaucrat) {
    if (_isSigned) return (Utils::printMsg("Form already Signed.", "red"));

    if (bureaucrat.getGrade() <= _signGrade) _isSigned = true;
    bureaucrat.signForm(_isSigned, _name);
}

const char* Form::SignedFormException::what() const _NOEXCEPT {
    return "Error: You can't initialize a signed form!";
}

const char* Form::EmptyNameException::what() const _NOEXCEPT {
    return "Error: name is required!";
}

const char* Form::GradeTooHighException::what() const _NOEXCEPT {
    return "Error: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const _NOEXCEPT {
    return "Error: Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os 
    << "Form Name: " << form.getName() << ".\n" 
    << "Form Signed State: " << (form.getIsSigned() ? "True" : "False")  << ".\n"
    << "Form Sign Grade: " << form.getSignGrade() << ".\n"
    << "Form Execute State: " << form.getExecuteGrade() << ".\n";

    return os;
}
