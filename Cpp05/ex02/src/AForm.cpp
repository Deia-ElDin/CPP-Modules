#include "AForm.hpp"
#include "Utils.hpp"

AForm::AForm()
    : _name("Default Form"), _isSigned(false), _signGrade(150), _executeGrade(150) {
    Utils::printMsg("Form default constructor called", "yellow");
}

AForm::AForm(
    const std::string&  name,
    const int           signGrade,
    const int           executeGrade
) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    Utils::printMsg("Form parameter constructor called", "yellow");

    if (name.empty()) throw EmptyNameException();
    else if (signGrade < 1 || executeGrade < 1) throw GradeTooHighException(); 
    else if (signGrade > 150 || executeGrade > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), 
      _isSigned(other._isSigned), 
      _signGrade(other._signGrade), 
      _executeGrade(other._executeGrade) {
    Utils::printMsg("Form copy constructor called", "yellow");
}

AForm& AForm::operator=(const AForm& other) {
    Utils::printMsg("Form assignation operator called", "yellow");

    if (this != &other) _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {
    Utils::printMsg("Form destructor called", "purple");
}

const   std::string	AForm::getName() const {
    return _name;
}

bool    AForm::getIsSigned() const {
    return _isSigned;
}

int     AForm::getSignGrade() const {
    return _signGrade;
}

int     AForm::getExecuteGrade() const {
    return _executeGrade;
}

void    AForm::beSigned(Bureaucrat &bureaucrat) {
    if (_isSigned) throw SignedFormException();

    if (bureaucrat.getGrade() > _signGrade) throw GradeTooLowException(); 

    _isSigned = true;  
}

const char* AForm::SignedFormException::what() const throw() {
    return "Error: Form already signed!";
}

const char* AForm::EmptyNameException::what() const throw() {
    return "Error: name is required!";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Error: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Error: Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Error: The form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os 
    << "Form Name: " << form.getName() << "." 
    << " Signed State: " << (form.getIsSigned() ? "True" : "False")  << "."
    << " Sign Grade: " << form.getSignGrade() << "."
    << " Execute Grade: " << form.getExecuteGrade() << ".";

    return os;
}
