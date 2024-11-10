#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form();
		Form(
			const std::string&	name,
			const int 			signGrade,
			const int 			executeGrade
		);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		void    			beSigned(Bureaucrat &bureaucrat);
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		class EmptyNameException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class SignedFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // __FORM_HPP__