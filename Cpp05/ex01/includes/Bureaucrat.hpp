#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include "Form.hpp"
#include <iostream>
#include <string>
#include <exception>

class Form; // Forward declaration

class Bureaucrat 
{
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
        void                signForm(Form &form);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif // __BUREAUCRAT_HPP__

/*
    Avoiding Circular Dependency:
        -   The Form class includes Bureaucrat.hpp (or vice versa in Bureaucrat.hpp), which can lead to circular dependencies if both headers include each other.
        -   A forward declaration tells the compiler that Bureaucrat is a class, allowing Form to reference it in function parameters without including Bureaucrat.hpp.

    Minimizing Header Inclusion:
        -   Including Bureaucrat.hpp in Form.hpp makes Form.hpp dependent on all of Bureaucrat.hpp's includes, increasing compile time and dependencies.
        -   With the forward declaration, Form only needs to know that Bureaucrat exists (not its implementation), allowing us to delay the actual inclusion of Bureaucrat.hpp until the .cpp file.
    
    Usage Context:
        -   You can use a forward declaration when you only reference the class in a pointer, reference, or function parameter (as in void beSigned(Bureaucrat &bureaucrat);).
        -   If you need to access any members or functions of Bureaucrat directly in Form.hpp, you’d need to include Bureaucrat.hpp instead.
*/
