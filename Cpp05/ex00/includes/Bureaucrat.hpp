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
                virtual const char* what() const throw();
        };

        class TooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif // __BUREAUCRAT_HPP__