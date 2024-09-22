#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat deia("Deia", 2);
        std::cout << deia << std::endl;

        deia.incrementGrade();
        std::cout << deia << std::endl;

        deia.incrementGrade();  
        std::cout << deia << std::endl;
    } catch (std::exception& e) {
        Utils::printErr(e.what());
    }

    try {
        Bureaucrat ahmed("Ahmed", 150);
        std::cout << ahmed << std::endl;

        ahmed.decrementGrade();
    } catch (std::exception& e) {
        Utils::printErr(e.what());
    }

    return 0;
}

/*
    1-  td::exception& e:

        -   The & indicates that you are catching the exception by reference. This means that e is a reference to the original exception object that was thrown, not a copy.

        -   Catching by reference is the preferred way to catch exceptions in C++ because it avoids unnecessary copying of the exception object and ensures that the polymorphic behavior (if using derived exception classes) is preserved.

    2-  Polymorphic Behavior:

        -   Since std::exception is the base class and TooHighException and TooLowException derive from it, catching by reference (std::exception&) allows the catch block to handle any exception derived from std::exception.
    
        -   The what() method, if overridden in a derived class, will be correctly called due to the virtual mechanism, even though you are catching the exception as a reference to the base class (std::exception).
    
    3-  Using what():

        -   e.what() will call the overridden what() method of the actual exception class (e.g., TooHighException or TooLowException), which provides the specific error message defined in those classes.
*/
