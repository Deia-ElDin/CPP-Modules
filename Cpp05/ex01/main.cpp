#include "Bureaucrat.hpp"
#include "Form.hpp"

void    testSignedForm() {
    try {
        Bureaucrat  deia("Deia", 2);
        Form        formA("Form-A", true, 1, 30);
    } catch (std::exception &e) {
        Utils::printErr(e.what());
    }
}

void    testSigning() {
    try {
        Bureaucrat  deia("Deia", 2);
        Form        formA("Form-A", false, 1, 30);

        formA.beSigned(deia);
        std::cout << formA << std::endl;

        std::cout << deia << std::endl;
        deia.incrementGrade();
        std::cout << deia << std::endl;

        formA.beSigned(deia);
        std::cout << formA << std::endl;

        formA.beSigned(deia);
        std::cout << formA << std::endl;
    } catch (std::exception &e) {
        Utils::printErr(e.what());
    }
}

int main() {
    int test = 2;

    test == 1 ? testSignedForm(): testSigning();
    return 0;
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
