#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    testShrubbery();
void    testRobotomy();
void    testPresidential();

int main() {
    int test = 3;

    if (test == 1) testShrubbery();
    else if (test == 2) testRobotomy();
    else testPresidential();
    return 0;
}

void    testShrubbery() {
    try {
    // Bureaucrat              deia("Deia", 146);
    Bureaucrat              deia("Deia", 138);
    ShrubberyCreationForm   formA("Form-A");

    std::cout << formA << std::endl;
    formA.beSigned(deia);
    std::cout << formA << std::endl;

    std::cout << deia << std::endl;
    deia.incrementGrade();
    std::cout << deia << std::endl;

    formA.beSigned(deia);
    deia.executeForm(formA);
    std::cout << formA << std::endl;

    } catch (std::exception &e) {
        Utils::printErr(e.what());
    }
}

void    testRobotomy() {
    try {
        Bureaucrat               deia("Deia", 72);
        // Bureaucrat               deia("Deia", 45);
        RobotomyRequestForm      formB("Form-B");

        std::cout << formB << std::endl;
        formB.beSigned(deia);
        std::cout << formB << std::endl;

        deia.executeForm(formB);
    } catch (std::exception &e) {
        Utils::printErr(e.what());
    }
}

void    testPresidential() {
      try {
        Bureaucrat              deia("Deia", 25);
        // Bureaucrat              deia("Deia", 5);
        PresidentialPardonForm  formC("Form-C");

        std::cout << formC << std::endl;
        formC.beSigned(deia);
        std::cout << formC << std::endl;

        deia.executeForm(formC);
    } catch (std::exception &e) {
        Utils::printErr(e.what());
    }
}

/*
    1-  std::exception& e:

        -   The & indicates that you are catching the exception by reference. This means that e is a reference to the original exception object that was thrown, not a copy.

        -   Catching by reference is the preferred way to catch exceptions in C++ because it avoids unnecessary copying of the exception object and ensures that the polymorphic behavior (if using derived exception classes) is preserved.

    2-  Polymorphic Behavior:

        -   Since std::exception is the base class and GradeTooHighException and GradeTooLowException derive from it, catching by reference (std::exception&) allows the catch block to handle any exception derived from std::exception.
    
        -   The what() method, if overridden in a derived class, will be correctly called due to the virtual mechanism, even though you are catching the exception as a reference to the base class (std::exception).
    
    3-  Using what():

        -   e.what() will call the overridden what() method of the actual exception class (e.g., GradeTooHighException or GradeTooLowException), which provides the specific error message defined in those classes.
*/
