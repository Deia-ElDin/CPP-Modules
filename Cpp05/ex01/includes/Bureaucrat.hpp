#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include "Utils.hpp"

class Bureaucrat {
    private:
    const std::string   _name;
    int                 _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string&  getName() const;
        int                 getGrade() const;
        void                incrementGrade();
        void                decrementGrade();

        class TooHighException : public std::exception {
            public:
                virtual const char* what() const _NOEXCEPT;
        };

        class TooLowException : public std::exception {
            public:
                virtual const char* what() const _NOEXCEPT;
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif // __BUREAUCRAT_HPP__

/*
    virtual const char* what() const throw();

        -   virtual: This means the function can be overridden in derived classes, which is essential for polymorphic behavior. When an exception is caught, the correct what() function (based on the actual type of the exception object) will be called.

        -   const: The function does not modify the object it is called on. This is because what() should only provide information about the exception and not alter the state of the object.

        -   what(): This is a standard function name for exception classes. It returns a C-style string (const char*) that describes the exception. This string is typically used to print an error message to the console. By overriding this method in your custom exception classes, you can provide a specific error message for each exception type.

        -   _NOEXCEPT (or simply noexcept in modern C++) specifies that the method does not throw any exceptions. This is important for exception handling, ensuring that calling what() itself does not cause another exception.
*/
