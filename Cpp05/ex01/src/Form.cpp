#include "Form.hpp"

Form::Form(
    const std::string& name,
    bool isSigned,
    const int signGrade,
    const int executeGrade
) : _name(name), _isSigned(isSigned), _signGrade(signGrade), _executeGrade(executeGrade) {
    Utils::printMsg("Form parameter constructor called", "yellow");

    if (signGrade < 1 || executeGrade < 1) 
        throw GradeTooHighException(); 
    else if (signGrade > 150 || executeGrade > 150) 
        throw GradeTooLowException();
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

    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
    Utils::printMsg("Form destructor called", "red");
}

void    Form::setName(const std::string& name) {
    if (name.empty())
        Utils::printErr("Empty name");
    _name = name;
}

void    Form::setIsSigned(bool isSigned) {
    _isSigned = isSigned;
}

void    Form::setSignGrade(const int signGrade) {
    if (signGrade < 1) throw GradeTooHighException(); 
    else if (signGrade > 150) throw GradeTooLowException();

    _signGrade = signGrade   
}

void    Form::setExecuteGrade(const int executeGrade) {
    if (executeGrade < 1) throw GradeTooHighException(); 
    else if (executeGrade > 150) throw GradeTooLowException();

    _executeGrade = executeGrade
}

void    Form::setForm(const std::string& name,
                      bool isSigned,
                      const int signGrade,
                      const int executeGrade) {
    setName(name);
    if (!_name) return ;
    setIsSigned(isSigned);
    setSignGrade(signGrade);
    setExecuteGrade(executeGrade);
}
                            

const   std::string	Form::getName() const {
    return _name;
}

bool    Form::getIsSigned() const {
    return _isSigned;
}

const int   Form::getSignGrade() const {
    return _signGrad;
}

const int   Form::getExecuteGrade() const {
    return _executeGrad;
}

const char* Form::NameException::what() const _NOEXCEPT {
    return "Error: name is invalid";
}

const char* Form::GradeTooHighException::what() const _NOEXCEPT {
    return "Error: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const _NOEXCEPT {
    return "Error: Grade is too low!";
}

// std::ostream& operator<<(std::ostream& os, const Form& form) {
//     os << form.getName() << f
// }